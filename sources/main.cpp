#include <QApplication>
#include <QPushButton>

int main( int argc, char *argv[] ) {
    QApplication app( argc, argv );
    
    QPushButton button( "AOchroma test" );
    button.show();
    
    return app.exec();
}