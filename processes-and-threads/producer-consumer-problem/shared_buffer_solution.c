#import <stdio.c>

// Common code (producer and consumer must agree on the buffer to be used)
#define BUFFER_SIZE 10

typedef {
  long int id;
  char[10] name;
} item;

item buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

int main() {
  return (0);
}

// Producer logic
void produce() {
  item next_produced;

  while (true) {
    while ((in + 1) % BUFFER_SIZE == out); // do noghing
  
    buffer[in] = next_produced;
    in += (in + 1) % BUFFER_SIZE;
  }
}

// Consumer logic
void consume() {
  item next_consumed;

  while (true) {
    while (in == out);

    next_consumed = buffer[out];
    out -= 1;
  }
}

