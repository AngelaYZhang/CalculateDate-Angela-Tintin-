#include "date_GUI.h"
#include "calculate_date.h"

[System::STAThreadAttribute]

void main(array<System::String^>^ args) {
	System::Windows::Forms::Application::EnableVisualStyles();
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);

	calculatedate::date_GUI form;
	//form.Show();
	System::Windows::Forms::Application::Run(% form);


}