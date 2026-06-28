#define IServiceProvider ComIServiceProvider
#include "VenPrin.h"
#include "VenMenu.h"
using namespace TFAlgoritmos;

int main() {
	Application::Run(gcnew VenMenu());
	//Application::Run(gcnew VenPrin());
}
