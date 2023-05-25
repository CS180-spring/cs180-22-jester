#include "jesterAPI.h"

using namespace std; 

int main(){

    jesterAPI api;
    api.init(); 
    // api.interface();
    api.interface();
    api.close(); 

    return 0; 

}