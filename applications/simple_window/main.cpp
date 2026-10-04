#include <EApplication>
#include <EWindow>

int main(){
    EToolkit::Application application;
    EToolkit::Window window;

    window.setText("EToolkit basic application");
    window.setBounds(100, 100, 800, 600);
    window.setEnability(true);
    window.setVisibility(true);

    return application.execute();
}