#include "/home/codeleaded/System/Static/Library/Files.h"
#include "/home/codeleaded/System/Static/Library/CStr.h"
#include "/home/codeleaded/System/Static/Library/Zip.h"

int main(){
    char Path[] = "./File.txt";
    
    FilesSize size;
    char* data = Files_ReadB(Path,&size);
    
    printf("Beginning: S: %u\n",size);
    void* compressed = Zip_Byte_zip(data,(long long[]){ size });
    printf("Compressed: S: %u\n",size);
    void* opened = Zip_Byte_open(compressed,(long long[]){ size });
    printf("Opened: S: %u\n",size);

    Files_Write(Path,opened,size);

    free(compressed);
    free(data);

    return 0;
}