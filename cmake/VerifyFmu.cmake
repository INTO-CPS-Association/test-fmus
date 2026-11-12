file(REMOVE_RECURSE "${VERIFY_DIR}")
file(MAKE_DIRECTORY "${VERIFY_DIR}")
file(ARCHIVE_EXTRACT INPUT "${ARCHIVE}" DESTINATION "${VERIFY_DIR}")
if(NOT EXISTS "${VERIFY_DIR}/modelDescription.xml" OR
   NOT EXISTS "${VERIFY_DIR}/binaries/${PLATFORM}/${BINARY_NAME}")
    message(FATAL_ERROR "Missing model description or platform library in ${ARCHIVE}")
endif()