#include "Controller.h"
#include "Vue.h"

int main()
{
    Vue vue;
    Controller controller{vue};
    controller.run();
    return 0;
}
