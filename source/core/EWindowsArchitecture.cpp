#include "../core/EWindowsArchitecture.hpp"

EToolkit::WindowsArchitecture::WindowsArchitecture(){

}

void EToolkit::WindowsArchitecture::SetVersion(WindowsVersion version){
    switch (version) {
        case WindowsVersion::Windows2000:
            #define _WIN32_WINNT 0x0500
            break;
        case WindowsVersion::WindowsXP:
            #define _WIN32_WINNT 0x0501
            break;
        case WindowsVersion::WindowsServer2003:
            #define _WIN32_WINNT 0x0502
            break;
        case WindowsVersion::WindowsServer2008:
            #define _WIN32_WINNT 0x0600
            break;
        case WindowsVersion::Windows7:
            #define _WIN32_WINNT 0x0601
            break;
        case WindowsVersion::Windows8:
            #define _WIN32_WINNT 0x0602
            break;
        case WindowsVersion::Windows8_1:
            #define _WIN32_WINNT 0x0603
            break;
        case WindowsVersion::Windows10:
            #define _WIN32_WINNT 0x0A00
            break;
        case WindowsVersion::Windows11:
            #define _WIN32_WINNT 0x0B00
            break;
    }
}
