/*!
  @author Shizuko Hattori
*/

#include "PyUtil.h"
#include "../ExecutablePath.h"
#include "../FloatingNumberString.h"

using namespace cnoid;
namespace py = pybind11;

namespace cnoid {

void exportPySignalTypes(py::module& m);
void exportPyValueTree(py::module& m);
void exportPyEigenTypes(py::module& m);
void exportPyEigenArchive(py::module& m);
void exportPySeqTypes(py::module& m);
void exportPySceneGraph(py::module& m);
void exportPyGeometryTypes(py::module& m);
void exportPyTaskTypes(py::module& m);

}

PYBIND11_PLUGIN(Util)
{
    py::module m("Util", "Python Utility Module");

    py::class_<Referenced, ReferencedPtr>(m, "Referenced");

    exportPySignalTypes(m);
    exportPyValueTree(m);
    exportPyEigenTypes(m);
    exportPyEigenArchive(m);
    exportPySeqTypes(m);
    exportPySceneGraph(m);
    exportPyGeometryTypes(m);
    exportPyTaskTypes(m);

    m.def("shareDirectory", &cnoid::shareDirectory);
    m.def("executablePath", &cnoid::executablePath);
    m.def("executableBasename", &cnoid::executableBasename);
    m.def("executableTopDirectory", &cnoid::executableTopDirectory);

    py::class_<FloatingNumberString>(m, "FloatingNumberString")
        .def(py::init<const std::string&>())
        .def("set", &FloatingNumberString::set)
        .def("setPositiveValue", &FloatingNumberString::setPositiveValue)
        .def("setNonNegativeValue", &FloatingNumberString::setNonNegativeValue)
        .def("value", &FloatingNumberString::value);

    return m.ptr();
}
