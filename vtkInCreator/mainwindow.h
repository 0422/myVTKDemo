#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "global_headers.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Renderer
    vtkSmartPointer<vtkRenderer> main_render_3d;

    // Render Window
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> renWin3D;
    // vtkSmartPointer<vtkGenericOpenGLRenderWindow> getRenderWindow();

    vtkSmartPointer<vtkActor> current_actor;
    vtkSmartPointer<vtkUnstructuredGrid> ugrid;


private slots:
    void on_pushButton_loadfile_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
