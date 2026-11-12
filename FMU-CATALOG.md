# FMU Catalog

Paths below are relative to this repository. Unless otherwise noted, the
Maestro origin is relative to the root of `INTO-CPS-Association/maestro`.
The output archive keeps the same FMI version, group and model path. The default
build contains all rows.

## FMI 2

| Model | Origin |
| --- | --- |
| `fmi2/initializer/watertank-c` | `plugins/initializer/src/test/resources/watertank-c.fmu` |
| `fmi2/initializer/watertankcontroller-c` | `plugins/initializer/src/test/resources/watertankcontroller-c.fmu` |
| `fmi2/jni/fmi2functiontest` | `org.intocps.maestro.fmi`, tag `Release/1.5.0`, `jnifmuapi/src/test/resources/fmus/fmi2/fmi2functiontest` |
| `fmi2/legacy/diff_pair` | `test-fmus` master, `diff_pair` |
| `fmi2/legacy/integrate` | `test-fmus` master, `integrate` |
| `fmi2/legacy/sine` | `test-fmus` master, `sine` |
| `fmi2/legacy/singlewatertank-20sim` | `test-fmus` master, `singlewatertank-20sim` |
| `fmi2/legacy/watertank-c` | `test-fmus` master, `watertank-c` |
| `fmi2/legacy/watertankcontroller-c` | `test-fmus` master, `watertankcontroller-c` |
| `fmi2/line-follow-robot/Body_Block` | `maestro/src/test/resources/LineFollowRobot_fmus/Body_Block.fmu` |
| `fmi2/line-follow-robot/LineFollower_Examples_SensorBlock1` | `maestro/src/test/resources/LineFollowRobot_fmus/LineFollower_Examples_SensorBlock1.fmu` |
| `fmi2/line-follow-robot/LineFollower_Examples_SensorBlock2` | `maestro/src/test/resources/LineFollowRobot_fmus/LineFollower_Examples_SensorBlock2.fmu` |
| `fmi2/line-follow-robot/Sensor_Block` | `maestro/src/test/resources/LineFollowRobot_fmus/Sensor_Block.fmu` |
| `fmi2/line-follow-robot/Sensor_Block_01` | `maestro/src/test/resources/LineFollowRobot_fmus/Sensor_Block_01.fmu` |
| `fmi2/line-follow-robot/Sensor_Block_02` | `maestro/src/test/resources/LineFollowRobot_fmus/Sensor_Block_02.fmu` |
| `fmi2/maestro/pump` | `maestro/src/test/resources/pump.fmu` |
| `fmi2/maestro/rollback-end` | `maestro/src/test/resources/rollback-end.fmu` |
| `fmi2/maestro/rollback-test` | `maestro/src/test/resources/rollback-test.fmu` |
| `fmi2/maestro/singlewatertank-20sim` | `maestro/src/test/resources/singlewatertank-20sim.fmu` |
| `fmi2/maestro/sink` | `maestro/src/test/resources/sink.fmu` |
| `fmi2/maestro/watertankcontroller-c` | `maestro/src/test/resources/watertankcontroller-c.fmu` |
| `fmi2/mass-spring-damper/MassSpringDamper1` | `maestro/src/test/resources/mass_spring_damper/MassSpringDamper1.fmu` |
| `fmi2/mass-spring-damper/MassSpringDamper2` | `maestro/src/test/resources/mass_spring_damper/MassSpringDamper2.fmu` |
| `fmi2/three-tank/threewatertank1` | `maestro/src/test/resources/three_tank/threewatertank1.fmu` |
| `fmi2/three-tank/threewatertank2` | `maestro/src/test/resources/three_tank/threewatertank2.fmu` |

## FMI 3

| Model | Origin |
| --- | --- |
| `fmi3/reference/BouncingBall` | `modelica/Reference-FMUs` release `v0.0.23` |
| `fmi3/reference/Feedthrough` | `modelica/Reference-FMUs` release `v0.0.23` |
| `fmi3/siggen-feedthrough/SignalGenerator` | `maestro/src/test/resources/fmi3/reference/siggen-feedthrough/SignalGenerator.fmu` |
| `fmi3/jni/fmi3functiontest` | `org.intocps.maestro.fmi`, tag `Release/1.5.0`, `jnifmuapi/src/test/resources/fmus/fmi3/fmi3functiontest`. Included in the default build and release with final FMI `3.0` metadata. |

## Variants And Changes

- The initializer and Maestro tank controllers have matching C sources but
  different metadata and resources; both are retained.
- The six legacy master-branch models are retained separately. Original 20-sim
  modeling files are under the models' `extra/org.intocps.testfmus/model`.
- Maestro's mass-spring-damper archive variants have identical non-binary files;
  their old binaries differ. The newly built models use the grouped copies above.
- The six line-follower plant/sensor archives match those in
  `INTO-CPS-Association/example-line_follower_robot`, master `FMUs/`.
- The identifiers of initializer and legacy `watertank-c`, `rollback-test`, and
  `rollback-end` were changed from hyphenated values to `watertank_c` or
  `rollback_end`; the binary names match. Both rollback C++ sources include
  `stdint.h` for GCC.
- JNI metadata uses the tokens expected by the native source. The FMI 2
  function-test `maxOutputDerivativeOrder` was corrected from `false` to `0`.
- The OpenModelica sensors retain fixes for missing `ctype.h` and `debugString`
  declarations and lazy memory-pool initialization. Their pinned support code
  also fixes a minimal-runtime duplicate definition and a zlib macOS check.
  They require the repository's `build-support` to compile their sources.

FMPy reports inherited metadata conformance findings for several of these
fixtures. Release notes contain the full report per FMU; a report is not a
simulation test and does not establish compatibility with Maestro.