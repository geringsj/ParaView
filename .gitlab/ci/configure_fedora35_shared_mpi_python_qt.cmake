set(PARAVIEW_ENABLE_EXAMPLES ON CACHE BOOL "")

set(PARAVIEW_ENABLE_ADIOS2 ON CACHE BOOL "")
set(PARAVIEW_ENABLE_FFMPEG ON CACHE BOOL "")
set(PARAVIEW_ENABLE_FIDES ON CACHE BOOL "")
# set(PARAVIEW_ENABLE_GDAL ON CACHE BOOL "")
# set(PARAVIEW_ENABLE_OPENTURNS ON CACHE BOOL "")
# set(PARAVIEW_ENABLE_PDAL ON CACHE BOOL "")
set(PARAVIEW_ENABLE_VISITBRIDGE ON CACHE BOOL "")
set(PARAVIEW_ENABLE_XDMF3 ON CACHE BOOL "")

set(PARAVIEW_PLUGINS_DEFAULT ON CACHE BOOL "")

set(PARAVIEW_PLUGIN_ENABLE_pvNVIDIAIndeX ON CACHE BOOL "")

set(PARAVIEW_PLUGIN_ENABLE_CDIReader ON CACHE BOOL "")

set(PARAVIEW_BUILD_TRANSLATIONS ON CACHE BOOL "")
set(PARAVIEW_TRANSLATIONS_DIRECTORY "$ENV{CI_PROJECT_DIR}/translations" CACHE BOOL "")

# External package settings.
# set(PARAVIEW_BUILD_WITH_EXTERNAL ON CACHE BOOL "")
# set(VTK_MODULE_USE_EXTERNAL_ParaView_vtkcatalyst OFF CACHE BOOL "")
# set(VTK_MODULE_USE_EXTERNAL_VTK_libharu OFF CACHE BOOL "")
# set(VTK_MODULE_USE_EXTERNAL_VTK_cgns OFF CACHE BOOL "")
# set(VTK_MODULE_USE_EXTERNAL_VTK_gl2ps OFF CACHE BOOL "")

set(PARAVIEW_XRInterface_OpenVR_Support ON CACHE BOOL "")
set(VTK_MODULE_ENABLE_VTK_RenderingOpenVR YES CACHE STRING "")
set(PARAVIEW_XRInterface_OpenXR_Support ON CACHE BOOL "")
set(VTK_MODULE_ENABLE_VTK_RenderingOpenXR YES CACHE STRING "")

include("${CMAKE_CURRENT_LIST_DIR}/configure_fedora35.cmake")
