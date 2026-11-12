# Test FMUs

Source-backed FMUs used by Maestro. The new catalog is organized under
`fmi2/<group>/<model>` and `fmi3/<group>/<model>`. Each directory contains the
model description, original sources and other retained FMU resources, without
prebuilt binaries. The former master-branch models are retained under
`fmi2/legacy`.

## Build

Requirements: CMake 3.21 or newer, Git, a C/C++ toolchain, and network access
to GitHub on the first configure. On Windows use the MSYS2 UCRT64 environment
with GCC, CMake and Ninja. On macOS, install the Xcode command line tools.

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel 4
ctest --test-dir build --output-on-failure --parallel 4
```

The 28 default archives (25 FMI 2 and 3 FMI 3) are written to `build/fmus/fmi2/...` and
`build/fmus/fmi3/...`. Linux and Windows builds target x86-64. macOS FMI 3
builds target the host architecture; FMI 2 libraries are universal binaries
containing x86-64 and arm64. Set `-DFMU_MACOS_UNIVERSAL_FMI2=OFF` to build
FMI 2 for the host only. Use separate build directories for different toolchains.

CMake fetches `modelica/fmi-standard` at release tags `v2.0.5` and `v3.0.2`.
It uses the corresponding version's headers; generated model sources may also
retain the exporter headers with which they were distributed. The two
OpenModelica models require the pinned support code in `build-support`.

GitHub Actions builds on Ubuntu 22.04 x86-64, Windows Server 2025 x86-64,
and macOS 26 on both Intel and Apple Silicon. The workflow verifies each
runner's architecture before building. The `test-fmus-all-platforms` workflow
artifact contains one FMU per model, with the Linux, Windows and macOS
libraries assembled inside it.
FMI 2 uses `linux64`, `win64` and `darwin64`; FMI 3 uses platform tuples.
The macOS FMI 2 library is universal. The per-platform artifacts are also
available for diagnosing individual builds.
Windows CI extracts and loads every packaged FMU with MSYS2 removed from
`PATH`, checking that its library can be loaded without MSYS2 runtime DLLs.

The Linux build uses Ubuntu 22.04's glibc baseline; older Linux systems may
still be incompatible. Windows binaries use the Universal C Runtime, included
with Windows 10 and later and Windows Server 2016 and later. The assembly and
release jobs do not compile binaries.

## Release

Run the **Release FMUs** workflow from GitHub Actions and enter a version such
as `1.0.0`. After every platform build and test succeeds, the workflow creates
the tag and GitHub release `Release/1.0.0`. It attaches `test-fmus.zip`, which
preserves the `fmi2` and `fmi3` directories, and each individual FMU as an
asset named by its path with `/` replaced by `--`. For example:

```text
https://github.com/INTO-CPS-Association/test-fmus/releases/download/Release%2F1.0.0/test-fmus.zip
```

Versions must be new; the workflow does not overwrite existing releases. Release
notes include FMPy's conformance findings for each FMU. These findings do not
block a release or determine whether the FMU works with Maestro. They include
inherited metadata issues such as missing initial unknowns and invalid
derivative declarations.

GitHub requires the manual release workflow to exist on the default branch
before it can be dispatched. Pushing a feature branch runs the build workflow;
it does not itself publish a release.

## Scope And Provenance

Three Overture standalone exports containing `.vdmrt` files are excluded.
The JNI FMI 3 function test is retained under `fmi3/jni`, but defaults to off:
its model description declares `3.0-beta.3`, not final FMI 3. Enable it only
for legacy testing with `-DFMU_INCLUDE_LEGACY_BETA=ON`. It is not included in
the combined workflow artifacts. Its token was changed to match the JNI test
source; the original Maestro archive declares a different token.

See [FMU-CATALOG.md](FMU-CATALOG.md) for individual model origins, preserved
variants and known changes.

| Models | Source |
| --- | --- |
| `fmi2/legacy` | Original `test-fmus` master-branch projects |
| Tanks, controllers, rollback models, pump, sink and mass-spring-dampers | Maestro test archives and the historical `INTO-CPS-Association/test-fmus` development branch |
| Robot body and sensors, three-tank models | Maestro test archives |
| FMI 2 and experimental FMI 3 JNI tests | `INTO-CPS-Association/org.intocps.maestro.fmi`, tag `Release/1.5.0` |
| FMI 3 BouncingBall and Feedthrough | `modelica/Reference-FMUs`, tag `v0.0.23` |
| FMI 3 SignalGenerator | Maestro test archive, Reference-FMUs-derived |
| OpenModelica runtime | `OpenModelica/OMCompiler`, commit `d19f8168993148b01716ef183b2877ecd44b006d` |
| OpenModelica tables and zlib | `modelica/ModelicaStandardLibrary`, tag `v3.2.2` |

License texts for the imported support code are in `build-support/licenses`.
OpenModelica imports retain the source-copy fixes needed for modern compilers.
The rollback sources explicitly include `stdint.h` for GCC. The FMI 2 JNI
description uses the native GUID and a valid integer derivative order. Four
legacy co-simulation identifiers containing hyphens were changed to valid C
identifiers, with their library names changed to match. These changes mean the
rebuilt FMUs are not byte-identical replacements for the original archives.

## Maestro Coverage

The audit covers 64 FMU archives tracked by Maestro, many of which are copies.
Source-backed archives without VDM-RT are represented in the catalog, with
distinct controller metadata retained. This is not a complete replacement for
all Maestro test inputs. The following are not in the default release:

- The standalone and interpreter-based controllers with `.vdmrt` files,
	including the line-follower, ESA, three-tank and GA controllers, are excluded.
- The `periodic_clock` and `sinewave_array` FMI 3 archives contain only Linux
	binaries. They were exported by Altair Activate without model sources.
- The pump and sink `mocked_fmus` used by code-generation tests have no native
	implementation sources; they are test doubles, not rebuilt simulation FMUs.
- The binary-only FMI 3 function-test archive has a source-backed counterpart in
	`fmi3/jni`, but it is a beta fixture with a changed token and is opt-in as
	described above.
- The line-follower repository's `3DanimationFMU.fmu` also has no source files;
	its two controllers contain VDM-RT. Its other six robot FMUs are included.

Some Maestro tests also download the Reference-FMUs `v0.0.23` bundle and JNI
`Release/1.5.0` test bundle. BouncingBall, Feedthrough and the FMI 2 JNI test are
included here; this repository does not replace those downloads in Maestro yet.

The tests check archive layout, native loading, version calls, and macOS FMI 2
architecture slices. They do not prove numerical equivalence, source-only FMU
rebuildability, or complete FMI behavioral conformance. The OpenModelica
archives in particular use build support from this repository; their retained
sources are not a self-contained source distribution. Validate individual FMUs
with the intended importer before relying on them.

Local verification so far covers macOS arm64 and x86-64 (the latter under
Rosetta), Ubuntu 22.04 x86-64 in an emulated container, and Windows x86-64
cross-compiled with MinGW and smoke-tested under Wine. GitHub-hosted CI and the
release workflow have not yet been run; Maestro's simulation tests have not
been run against these new combined archives.
