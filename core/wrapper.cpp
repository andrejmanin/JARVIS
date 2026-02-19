#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "worker.h"

namespace py = pybind11;

PYBIND11_MODULE(worker, m) {
    py::class_<Worker>(m, "Worker")
        .def(py::init<>())
        .def("detectFromText", &Worker::detectFromText);
}
