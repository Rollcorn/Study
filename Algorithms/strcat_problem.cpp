#include <cstring>
#include <cstdio>
#include <cstdlib>

int main()
{
  const char* s = "Hello, world! ";
  printf("%s\n", s);
 
  int times_to_concatenate;
  scanf("%d", &times_to_concatenate);

  size_t buffer_length = strlen(s) * times_to_concatenate + 1;
  char* buffer = '\0';
  printf("%s\n", buffer);

  for (int i = 0; i < times_to_concatenate; i++){
      strcat(buffer, s);
      printf("%s\n", buffer); 

  }
  
  free(buffer);
  
  return 0;
}
