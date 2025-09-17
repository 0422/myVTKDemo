#ifndef GLOBAL_HEADERS_H
#define GLOBAL_HEADERS_H

#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2)
VTK_MODULE_INIT(vtkInteractionStyle)
VTK_MODULE_INIT(vtkRenderingFreeType)
VTK_MODULE_INIT(vtkRenderingVolumeOpenGL2)

#include <vtkVersion.h>
#include <vtkActor.h>
#include <vtkAreaPicker.h>
#include <vtkDataSetMapper.h>
#include <vtkDataSetSurfaceFilter.h>
#include <vtkExtractPolyDataGeometry.h>
#include <vtkExtractDataSets.h>
// #include <vtkFilter.h>
#include <vtkIdTypeArray.h>
#include <vtkInteractorStyleRubberBandPick.h>
#include <vtkObjectFactory.h>
#include <vtkPlanes.h>
#include <vtkPointData.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderer.h>
// #include <vtkRenderCollection.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>
#include <vtkSphereSource.h>
#include <vtkUnstructuredGrid.h>
#include <vtkVersion.h>
#include <vtkVertexGlyphFilter.h>
#include <vtkUnstructuredGridReader.h>
#include <vtkExtractSelectedFrustum.h>
#include <vtkExtractGeometry.h>
#include <vtkUnstructuredGrid.h>
#include <vtkCellData.h>
#include <vtkIntArray.h>
#define VTKISRBP_ORIENT 0
#define VTKISRBP_SELECT 1
// VTK
#include <vtkAssembly.h>
#include <vtkPolyData.h>
#include <vtkSTLReader.h>
#include <vtkSmartPointer.h>
#include <vtkPolyDataMapper.h>
#include <vtkDataSetMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkOrientationMarkerWidget.h>
#include <vtkAxesActor.h>
#include <vtkCubeAxesActor.h>
#include <vtkCamera.h>
#include <vtkClipPolyData.h>
#include <vtkPlane.h>
#include <vtkProperty.h>
#include <vtkCubeSource.h>
#include <vtkCaptionActor2D.h>
#include <vtkProperty2D.h>
#include <vtkColor.h>
#include <vtkTextProperty.h>
#include <vtkShrinkFilter.h>
#include <vtkNamedColors.h>
#include <vtkLight.h>
#include <vtkUnstructuredGridReader.h>
// #include <vtkConeSource> // 源数据
#include <vtkUnstructuredGrid.h>
#include <vtkPolyDataMapper.h> // 数据映射
#include <vtkUnstructuredGridReader.h>
#include <vtkDataSetMapper.h>
#include <vtkRenderer.h> // 绘制器
#include <vtkRenderWindow.h> // 绘制窗口
#include <vtkActor.h> // 演员
#include <vtkCamera.h> // 照相机
#include <vtkRenderWindowInteractor.h> // 加入交互机制类
#include <vtkMath.h>
#include <vtkRectilinearGrid.h>
#include <vtkDoubleArray.h>
#include <vtkResampleWithDataSet.h>
#include <vtkCellData.h>
#include <vtkPointData.h>
#include <vtkLookupTable.h>
#include <vtkCellDataToPointData.h>
#include <vtkScalarBarActor.h>
#include <vtkContourFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkReflectionFilter.h>
#include <vtkLookupTable.h>
#include <vtkCellDataToPointData.h>
#include <vtkScalarBarActor.h>
#include <vtkContourFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkReflectionFilter.h>

/*
#include <QObject>
#include <QDebug>
#include <QColor>
#include <QDialog>
#include <QDir>
#include <QFileDialog>
#include <QFileInfoList>
#include <QColorDialog>
#include <QDir>
#include <QFileDialog>
#include <QString>
#include <QFileInfoList>
#include <QDebug>
*/
#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

#pragma execution_character_set("utf-8")

#endif // GLOBAL_HEADERS_H
