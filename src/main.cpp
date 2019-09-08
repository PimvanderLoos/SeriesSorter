#include "main.ih"

// TODO: Check full path for name/season/year/etc extraction, not only filename and parent directory name.
//       The problem arises with "/Movie/subs/eng.srt", for example.
// TODO: Ignore sample folders.
// TODO: Config file.
// TODO: Check if similar files already exist (for series). i.e. so that "Hawaii Five 0 2010" and "Hawaii Five0 2010"
//       Both result in the same folder (whichever one existed first, I don't care).

int main()
{
    size_t sleepTime = 300;
    FileReader fr;
    while(true)
    {
        fr.run();
        // Run every 5 minutes
        sleep(sleepTime);
    }
}