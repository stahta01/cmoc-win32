
#include "_stdlib.h"

int system(char* cmd)
{
    int result = true;
    if (cmd) {
        try {
            systemex(cmd);
        }
        except {
            result = current_exception->errno;
        } else {
            result = 0;
        }
    }
    return result;
}

