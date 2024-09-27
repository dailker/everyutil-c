#include <stdio.h>
#include <unistd.h>
#include "file/ensure_dir.h"
#include "file/file_exists.h"

int main(void) {
    int result = ensure_dir("test_dir/sub_dir");
    printf("Ensure dir test: %s\n", (result == 0 && file_exists("test_dir/sub_dir")) ? "PASSED" : "FAILED");
    
    // Cleanup
    rmdir("test_dir/sub_dir");
    rmdir("test_dir");
    
    return 0;
}