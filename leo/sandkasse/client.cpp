//
//  Pubsub envelope subscriber
//
// Olivier Chamoux <olivier.chamoux@fr.thalesgroup.com>

#include <Python.h>
#include "zhelpers.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace zmq;

static const char* PLUGIN_SUB  = "mouseControl";

std::string SubPlugIn(const std::string& ln);

int main () {
	// initialyse the python interpreter
	Py_Initialize();
	PyObject* sysPath = PySys_GetObject((char*)"path");
	PyList_Append(sysPath, PyString_FromString("."));
	
    //  Prepare our context and subscriber
    zmq::context_t context(1);
    zmq::socket_t subscriber (context, ZMQ_SUB);
    subscriber.connect("tcp://192.168.1.145:5562");
    subscriber.setsockopt( ZMQ_SUBSCRIBE, "A", 1);
    

    while (1) 
    {
        //  Read envelope with address and message contents
        std::string address = s_recv (subscriber);        
        std::string contents = s_recv (subscriber);
        
        SubPlugIn(contents);
	}
    
    Py_Finalize();
    return 0;
}


std::string SubPlugIn(const std::string& ln)
{
    PyObject* pluginModule = PyImport_Import(PyString_FromString(PLUGIN_SUB));
    if (!pluginModule)
    {
        PyErr_Print();
        return "Error importing module";
    }
    
    PyObject* filterFunc = PyObject_GetAttrString(pluginModule, "subscriber");
    if (!filterFunc)
    {
        PyErr_Print();
        return "Error retrieving 'filterFunc'";
    }

    PyObject* args = Py_BuildValue("(s)", ln.c_str());
    if (!args)
    {
        PyErr_Print();
        return "Error building args tuple";
    }
  
    PyObject* result = PyObject_CallObject(filterFunc, args);
    if (!result)
    {
        PyErr_Print();
        return "Error invoking 'filterFunc'";
    }
    
    const char* cResult = PyString_AsString(result);
    if (!cResult)
    {
        PyErr_Print();
        return "Error converting result to C string";
    }
    
    return cResult;
}





