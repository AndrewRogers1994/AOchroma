#pragma once
#include <QApplication>
#include <QPushButton>
#include "tinyxml2.h"
#include <fstream>


using namespace tinyxml2;
using namespace std;

//Hardcoded path for my installation, this will be changed once we have it setup to do so.
string path = "E:\\OLD AO\\Anarchy Online\\cd_image\\gui\\Default\\";

bool file_exist(string fileName) {
    string filePath = path + fileName.c_str();
    std::ifstream infile( filePath );
    return infile.good();
}
void copyFile(string orig, string copy) {
    FILE *src = fopen( orig.c_str(), "rb" );
    FILE *dst = fopen( copy.c_str(), "wb" );
    int i;
    for ( i = getc( src ); i != EOF; i = getc( src ) ) {
        putc( i, dst );
    }
    fclose( dst );
    fclose( src );
}

void CreateBackup(string filename) {
    string defaultFileName = filename + "Default.xml";

    if( !file_exist( defaultFileName ) ) {
        if( file_exist( filename + ".xml" ) ) {
            copyFile( (path + filename + ".xml"), (path + defaultFileName) );
        } else {
            qDebug( "Default file missing" );
        }
    } else {
        qDebug( (filename + "Default Already exists skipping backup").c_str() );
    }
}


void CreateDefaultFiles() {
    CreateBackup( "TextColors" );
    CreateBackup( "GUIColors" );
    CreateBackup( "MainPrefs" );
}


int main( int argc, char *argv[] ) {
    QApplication app( argc, argv );   
    QPushButton button( "AOchroma test" );
    button.show();
    CreateDefaultFiles();
    return app.exec();
}

