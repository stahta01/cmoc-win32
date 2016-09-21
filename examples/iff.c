
#include <stdio.h>
#include <stdlib.h>
#include <iff.h>

int main(void)
{
    system("DRIVE1");
    FILE* fp = fopen("IMAGE.IFF", "r");
    if (fp) {
        iff_head_t head;
        if (iff_head_read(&head, fp) && iff_head_is(&head, "FORM")) {
            char buf[2000];
            fread(buf, 4, 1, fp);
            while (iff_head_read(&head, fp)) {
                fread(buf, 1, head.size.lo, fp);
                if (iff_head_is(&head, "BODY")) {
                    puts("BODY FOUND");
                }
            }
        }
        fclose(fp);
    }
    return 0;
}

