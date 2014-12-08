/*!
  @author Shin'ichiro Nakaoka
*/

#include "../MainWindow.h"
#include "../ToolBar.h"
#include "../ToolBarArea.h"
#include "../ViewArea.h"
#include <boost/python.hpp>

using namespace boost::python;
using namespace cnoid;

namespace cnoid {

void exportPyMainWindow()
{
    class_<MainWindow, MainWindow*, bases<QMainWindow>, boost::noncopyable>("MainWindow", no_init)
        .def("instance", &MainWindow::instance, return_value_policy<reference_existing_object>()).staticmethod("instance")
        .def("setProjectTitle", &MainWindow::setProjectTitle)
        //.def("toolBarArea", &MainWindow::toolBarArea)
    //.def("viewArea", &MainWindow::viewArea)
        .def("addToolBar", &MainWindow::addToolBar);

/*
    class_<ToolBarArea, ToolBarArea*, bases<QWidget>, boost::noncopyable>("ToolBarArea", no_init)
        .def("addToolBar", &ToolBarArea::addToolBar)
        .def("removeToolBar", &ToolBarArea::removeToolBar);
*/

/*
    class_<ViewArea, ViewArea*, bases<QWidget>, boost::noncopyable>("ViewArea", no_init)
        .def("addView", &ViewArea::addView)
        .def("removeView", &ViewArea::removeView)
        .def("numViews", &ViewArea::numViews);
*/
}

}