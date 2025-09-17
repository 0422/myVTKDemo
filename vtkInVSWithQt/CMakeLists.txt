cmake_minimum_required(VERSION 3.10)

project(combineQtAndVTK)


# 导入Qt的库
find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED)


# Qt提供的自动复制依赖库的工具 E:\QtSpace\softwares\qt515\5.15.2\msvc2019_64\bin\windeployqt.exe


find_package(VTK REQUIRED)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 垃圾csdn
# CMAKE配置项: 包含当前目录 on
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# CMAKE配置项: 是否为Qt目标自动处理 uic 
set(CMAKE_AUTOUIC ON)
# CMAKE配置项: 是否为Qt目标自动处理 moc
set(CMAKE_AUTOMOC ON)
# CMAKE配置项: 是否为Qt目标自动处理 rcc
set(CMAKE_AUTORCC ON)


# 添加源文件
set(SOURCES
    main.cpp
    mainwindow.cpp
)

# 添加头文件
set(HEADERS
    global_headers.h
    mainwindow.h
)

# 添加UI文件
set(UI_FILES
    mainwindow.ui
)

# 通过Qt的uic.exe生成UI文件对应的ui_xxx.h文件并将该文件存在变量UI_FILES里
#qt5_wrap_ui(UI_HEADERS ${UI_FILES})

# 通过Qt的moc.exe将包含Q_OBJECT的头文件生成对应的moc_xxx.cxx文件并存储在变量HEADERS中
#qt5_wrap_cpp(MOC_SOURCES ${HEADERS})

# Qt的MOC和UIC生成的ui_xxx.h文件、moc_xxx.cxx文件存放在cmake的“where to build binaries”指定的目录里
# 所以要将这些路径包含进来
#include_directories(${PROJECT_SOURCE_DIR}
#    ${CMAKE_CURRENT_BINARY_DIR}
#)

# 如果有qt资源文件.qrc 
# qt5_add_resources 用Qt的rcc.exe生成相应的qrc_xxxx.cpp文件并将生成的文件列表存在变量Project_RCC_SRCS中
#set(Project_RCCS
#    project.qrc
#)
#qt5_add_resources(Project_RCC_SRCS ${Project_RCCS})


# 根据程序的cpp、h、以及生成的ui_xxx.h、moc_xxx.cxx、qrc_xxxx.cpp等，生成可执行文件，并链接Qt的动态库（Qt动态库都定义在QT_LIBRARIES变量了）
add_executable(combineQtAndVTK 
        ${SOURCES} 
        ${HEADERS} 
        ${UI_FILES} 
)


# 为 TestVTKInstall 目标指定 VTK 的 include 目录
target_include_directories(combineQtAndVTK PRIVATE "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/include/vtk-9.1")

# 链接 VTK 库（假设你已经知道库路径）
target_link_libraries(combineQtAndVTK PRIVATE 
    Qt5::Widgets
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkcgns-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkChartsCore-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkCommonColor-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkCommonComputationalGeometry-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkCommonCore-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkCommonDataModel-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkCommonExecutionModel-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkCommonMath-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkCommonMisc-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkCommonSystem-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkCommonTransforms-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkDICOMParser-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkDomainsChemistry-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkDomainsChemistryOpenGL2-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkdoubleconversion-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkexodusII-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkexpat-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkFiltersAMR-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkFiltersCore-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkFiltersExtraction-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkFiltersFlowPaths-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkFiltersGeneral-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkFiltersGeneric-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkFiltersGeometry-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkFiltersHybrid-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkFiltersHyperTree-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkFiltersImaging-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkFiltersModeling-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkFiltersParallel-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkFiltersParallelImaging-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkFiltersPoints-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkFiltersProgrammable-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkFiltersSelection-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkFiltersSMP-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkFiltersSources-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkFiltersStatistics-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkFiltersTexture-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkFiltersTopology-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkFiltersVerdict-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkfmt-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkfreetype-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkGeovisCore-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkgl2ps-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkglew-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkGUISupportQt-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkGUISupportQtQuick-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkGUISupportQtSQL-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkhdf5-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkhdf5_hl-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkImagingColor-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkImagingCore-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkImagingFourier-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkImagingGeneral-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkImagingHybrid-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkImagingMath-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkImagingMorphological-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkImagingSources-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkImagingStatistics-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkImagingStencil-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkInfovisCore-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkInfovisLayout-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkInteractionImage-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkInteractionStyle-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkInteractionWidgets-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkIOAMR-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkIOAsynchronous-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkIOCGNSReader-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkIOChemistry-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkIOCityGML-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkIOCONVERGECFD-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkIOCore-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkIOEnSight-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkIOExodus-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkIOExport-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkIOExportGL2PS-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkIOExportPDF-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkIOGeometry-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkIOHDF-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkIOImage-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkIOImport-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkIOInfovis-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkIOIOSS-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkIOLegacy-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkIOLSDyna-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkIOMINC-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkIOMotionFX-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkIOMovie-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkIONetCDF-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkIOOggTheora-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkIOParallel-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkIOParallelXML-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkIOPLY-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkIOSegY-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkIOSQL-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkioss-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkIOTecplotTable-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkIOVeraOut-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkIOVideo-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkIOXML-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkIOXMLParser-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkjpeg-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkjsoncpp-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkkissfft-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtklibharu-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtklibproj-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtklibxml2-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkloguru-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtklz4-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtklzma-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkmetaio-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtknetcdf-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkogg-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkParallelCore-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkParallelDIY-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkpng-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkpugixml-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkRenderingAnnotation-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkRenderingContext2D-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkRenderingContextOpenGL2-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkRenderingCore-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkRenderingFreeType-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkRenderingGL2PSOpenGL2-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkRenderingImage-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkRenderingLabel-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkRenderingLOD-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkRenderingOpenGL2-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkRenderingQt-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkRenderingSceneGraph-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkRenderingUI-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkRenderingVolume-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkRenderingVolumeOpenGL2-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkRenderingVtkJS-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtksqlite-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtksys-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkTestingRendering-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtktheora-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtktiff-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkverdict-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkViewsContext2D-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkViewsCore-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkViewsInfovis-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkViewsQt-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkWrappingTools-9.1d.lib"
    "E:/vtkSpace/resource/vtk_9_1_0/VTK-9.1.0-install-debug/lib/vtkzlib-9.1d.lib"
)