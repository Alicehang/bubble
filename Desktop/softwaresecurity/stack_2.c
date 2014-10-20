void fn(int arg1, int arg2) {
  int x; int y;
  x=3; y=4;
  printf("now we are in fn\n");
}

main () {
  int a; int b;
  a=1; b=2;
  fn(a, b);
}
