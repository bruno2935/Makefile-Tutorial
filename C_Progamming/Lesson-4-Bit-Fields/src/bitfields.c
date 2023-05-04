// #include <stdbool.h>
// #include <stdint.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <time.h>

// #define TS_BUF_LENGTH 30

// // Define my options
// #define LOG_TIME 0x01      // 0xb00000001
// #define LOG_DATE 0x02      // 0xb00000010
// #define LOG_USER 0x04      // 0xb00000100
// #define LOG_COUNT 0x08     // 0xb00001000
// #define LOG_ALL 0xFF       // 0xb11111111
// #define LOLG_FULTIME 0x03  // 0xb00000011

// int getlogin() {
//     return 14235;
// }

// void logmsgs(FILE *fp, char *message, uint8_t options) {
//     static uint64_t logcount = 0;

//     time_t time_val;
//     char timestamp[TS_BUF_LENGTH];
//     char datestamp[TS_BUF_LENGTH];
//     struct tm *tm_info;

//     time_val = time(NULL);
//     tm_info = localtime(&time_val);
//     strftime(datestamp, TS_BUF_LENGTH, "%Y-%m-%d (%a)", tm_info);
//     strftime(timestamp, TS_BUF_LENGTH, "%H:%M:%S", tm_info);

//     if (options & LOG_COUNT)
//         fprintf(fp, "%lld, ", ++logcount);

//     if (options & LOG_DATE)
//         fprintf(fp, "%s, ", datestamp);

//     if (options & LOG_TIME)
//         fprintf(fp, "%s, ", timestamp);

//     if (options & LOG_USER)
//         fprintf(fp, "%d, ", getlogin());

//     fprintf(fp, "%s\n", message);
// }

// int main() {
//     logmsgs(stdout, "Things are running fine", 0);
//     logmsgs(stdout, "Hmmm...maybe you should stop", LOG_USER | LOG_DATE);
//     logmsgs(stdout, "Another random menssage", LOG_USER | LOG_DATE | LOG_TIME);
//     logmsgs(stdout, "Try another visual studio extension", LOG_COUNT);
//     logmsgs(stdout, "Try another visual studio extension", LOG_ALL);
//     return 0;
// }