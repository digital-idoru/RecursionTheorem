#include <stdio.h>
void q(char*); 


int main(int argc, const char** argv) {


  q(argv[1]);

  return 0;
}

void q(char* w) {
  /** 
  
      The buildup to the recursion theorem is to create a TM that can print it's own description to its tape and halt.
      To do this, Sipser first proves that there exists a total recursive function (computable function) q, such that, 
      given any string w \in \Sigma^*, q(w) = P_{w}. Where P is a TM that prints the string w and halts. 

      Thus, to recape, q is a total recursive function such that, given any string w, q constructs a TM P such that P 
      ignores its input and only prints w. 
  
  **/
  

  FILE* output = NULL;
  char name[50] = { 0 }; 
  char func[10000] = { 0 };
  
  sprintf(name, "%s.c", w);
  sprintf(func, "#include <stdio.h>\n\nint main(int argc, const char** argv) {\n\n printf(\"%s\"); \n\n return 0; \n\n}", w);
  
  output = fopen(name, "w");
  fprintf(output, "%s", func);
  fclose(output);
  
  return;
}
