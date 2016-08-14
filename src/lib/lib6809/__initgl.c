
// This is a dummy INITGL for initial linking. cmoc2 uses a double link.
// The first link is used to obtain a link map file which is used to
// locate all the INITGL's for each object file. The real INITGL is created
// and added to the projects archive. The second link will find the
// real autocreated INITGL first, and link to that.

void asm __initgl()
{
    asm {
        INITGL: export
        INITGL:
    }
}

