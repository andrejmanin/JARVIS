#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "worker.h"

namespace py = pybind11;

PYBIND11_MODULE(worker, m) {
    py::class_<IntentResult>(m, "IntentResult")
        .def_readonly("intentName", &IntentResult::name)
        .def_readonly("confidence", &IntentResult::confidence);

    py::class_<Worker>(m, "Worker")
        .def("detectFromText", &Worker::detectFromText)
        .def("getIntents", &Worker::getIntents);

}
