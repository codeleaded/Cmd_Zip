#include "/home/codeleaded/System/Static/Library/Files.h"
#include "/home/codeleaded/System/Static/Library/CStr.h"
#include "/home/codeleaded/System/Static/Library/Zip.h"

int main(){
    //char Path[] = "./data/File.txt";
    char Path[] = "./data/Car_Green_Fast.png";
    char Out[] = "./data/Car_Green_Fast_OUT.png";
    
    FilesSize fsize;
    char* data = Files_ReadB(Path,&fsize);
    if(data){
        printf("Opened: '%s'\n",Path);
        printf("Beginning: S: %u\n",fsize);
    
        Zip_Size csize = fsize;
        void* compressed = Zip_Compress(data,&csize,4);
        printf("Compressed: S: %llu\n",csize);
        
        Zip_Size dsize = csize;
        Zip_Size rdsize = Zip_Decompress_Size(compressed,&dsize);
        void* opened = Zip_Decompress(compressed,&dsize);
        printf("Opened: S: %llu (%llu)\n",dsize,rdsize);

        printf("Output: '%s' -> %lf %%\n",Path,(double)csize / (double)fsize * 100.0);
        Files_Write(Out,opened,rdsize);

        free(compressed);
        free(data);
    }else{
        printf("Can't open: '%s'\n",Path);
    }

    return 0;
}