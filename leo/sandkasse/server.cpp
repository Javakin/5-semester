//
//  Pubsub envelope publisher
//  Note that the zhelpers.h file also provides s_sendmore
//
// Olivier Chamoux <olivier.chamoux@fr.thalesgroup.com>

#include <Python.h>
#include "zhelpers.hpp"
#include <iostream>
#include <string>


using namespace std;
using namespace zmq;

static const char* PLUGIN_PUB  = "mouseControl";

std::string PubPlugIn(const std::string& ln);


int main () {
	// initialyse the python interpreter
	Py_Initialize();
	PyObject* sysPath = PySys_GetObject((char*)"path");
	PyList_Append(sysPath, PyString_FromString("."));
	
	//  Prepare our context and publisher
	zmq::context_t context(1);
	zmq::socket_t publisher(context, ZMQ_PUB);
	publisher.bind("tcp://*:5561");
		
	
	while (1)
	{
		// send information
        s_sendmore (publisher, "A");
        s_send (publisher, PubPlugIn("dummy"));
        sleep(1);
    }
    
    
    Py_Finalize();
    return 0;
}

std::string PubPlugIn(const std::string& ln)
{
    PyObject* pluginModule = PyImport_Import(PyString_FromString(PLUGIN_PUB));
    if (!pluginModule)
    {
        PyErr_Print();
        return "Error importing module";
    }
    
    PyObject* filterFunc = PyObject_GetAttrString(pluginModule, "publisher");
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

