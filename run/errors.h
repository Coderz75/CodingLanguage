#ifndef ERRORS_H
#define ERRORS_H

#include "slackerz/default.h"
#include "color/termcolor.hpp"

void cerror(int line, string error, string faultline,string tips = ""){
    cout << termcolor::red << "ERROR: On line: " + to_string(line) + "\n\n"<<termcolor::underline<< line << "| " << faultline<<termcolor::reset<<termcolor::red<<"\n\n"<<error << termcolor::green<<"\n\nTips:\n\t" << tips << termcolor::red<< "\nCompilation Terminated\n";
    cout<< termcolor::reset;
    exit(EXIT_FAILURE);
}

void cerror(int line, string error, string faultline,string prevline,string nextline,string tips = ""){
    cout << termcolor::red << "ERROR: On line: " + to_string(line) + "\n";

    cout << termcolor::reset << line-1 << "| " << prevline << "\n";

    cout<< termcolor::red<<termcolor::underline<< line << "| " << faultline << "\n";
    cout << termcolor::reset << line +1 << "| "<< nextline;
    cout << termcolor::reset<<termcolor::red<<"\n\n"<<error;
    cout<< termcolor::green<<"\n\nTips:\n\t" << tips ;
    cout<<termcolor::red<< "\nCompilation Terminated\n";
    cout<< termcolor::reset;
    exit(EXIT_FAILURE);
}

void cerrorNotem(int line, string error, string faultline,string prevline,string nextline,string tips = ""){
    cout << termcolor::red << "ERROR: On line: " + to_string(line) + "\n";

    cout << termcolor::reset << line-1 << "| " << prevline << "\n";

    cout<< termcolor::red<<termcolor::underline<< line << "| " << faultline << "\n";
    cout << termcolor::reset << line +1 << "| "<< nextline;
    cout << termcolor::reset<<termcolor::red<<"\n\n"<<error;

    cout<< termcolor::green<<"\n\nTips:\n\t" << tips ;
    cout<< termcolor::reset;

}

void cerror(string error){
    cout << termcolor::red << error << "\nCompilation Terminated\n";
    cout << termcolor::reset;
    exit(EXIT_FAILURE);
}

void warn(string warnmsg){
    cout << termcolor::yellow << "WARNING: " << warnmsg << termcolor::reset << "\n";
}

void warn(int line, string warnmsg){
    cout << termcolor::yellow << "WARNING [line: "<<tostring(line)<< "]: " << warnmsg << termcolor::reset << "\n";
}


void givetips(string& errorType, string& tips){
    
    if(errorType == " error C2143" or str(errorType).endswith("before ‘;’ token")){
        
        tips = "You might be missing a terminating charachter in one of the previous lines";
    }
    if(errorType == " error C2065" or str(errorType).endswith("was not declared in this scope")){
        
        tips = "Make sure the line is not nonsense \n\tIf it isn't nonesense, make sure the identifier is defined in the given scope";
    }
}

#endif