include("F:/MAKS/SpellCheckService/Application/build/Complect_C-Debug/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/SpellCheckService-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE "F:/MAKS/SpellCheckService/Application/build/Complect_C-Debug/SpellCheckService.exe"
    GENERATE_QT_CONF
)
