#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <termios.h>
#include <string.h>
#include <sys/ioctl.h>
#include <errno.h>

// #include <stdio.h>
// #include <signal.h>
// #include <sys/time.h>
// #include <unistd.h>

const char default_path[] = "/dev/ttyACM0";

int set_tty(int fd, int baud, int bits, int parity, int stop);
uint8_t str2hex(uint8_t *in_buf, uint8_t *out_buf, uint16_t *out_size);
// void signalHandler(int signo);

// volatile char timer_flag = 0;
// struct timeval tv;

int main(int argc, char *argv[])
{
   int serial_port;
   int length;
   char *path;
   uint8_t tmp_buf[1024];

   //若无输入参数则使用默认终端设备
   if (argc > 1)
      path = argv[1];
   else
      path = (char *)default_path;

   //获取串口设备描述符
   printf("This is tty/usart demo.\n");
   serial_port = open(path, O_RDWR);
   if (serial_port < 0)
   {
      printf("Fail to Open %s device\n", path);
      return 0;
   }
   else
   {
      printf("open %s ok\n", path);
   }

   set_tty(serial_port, 115200, 8, 'N', 1);

   uint8_t in_buf[] = "AA AA AA AA 00 16 53 59 53 54 45 4D 20 43 52 43 20 30 30 20 31 31 20 32 32 20 33 33 5F F8 0D 0A";
   // uint8_t in_buf[] = "AA AA AA AA 00 0B 53 59 53 54 45 4D 20 54 45 53 54 D1 6B 0D 0A";
   // \xAA\xAA\xAA\xAA\x00\x0B\x53\x59\x53\x54\x45\x4D\x20\x54\x45\x53\x54\xD1\x6B\x0D\x0A                                 1MB
   // \xAA\xAA\xAA\xAA\x00\x13\x53\x59\x53\x54\x45\x4D\x20\x54\x45\x53\x54\x20\x31\x30\x32\x34\x20\x4B\x42\x7B\xE2\x0D\x0A    1024KB
   // \xAA\xAA\xAA\xAA\x00\x11\x53\x59\x53\x54\x45\x4D\x20\x54\x45\x53\x54\x20\x32\x30\x20\x4D\x42\x23\xB8\x0D\x0A         20MB
   // \xAA\xAA\xAA\xAA\x00\x0F\x53\x59\x53\x54\x45\x4D\x20\x54\x45\x53\x54\x20\x31\x30\x30\xC3\xE2\x0D\x0A                 100MB
   // \xAA\xAA\xAA\xAA\x00\x13\x53\x59\x53\x54\x45\x4D\x20\x54\x45\x53\x54\x20\x31\x30\x32\x34\x20\x4D\x42\xD1\x44\x0D\x0A    1GB
   uint8_t out_buf[50];
   uint16_t out_size;
   str2hex(in_buf, out_buf, &out_size);
   write(serial_port, out_buf, out_size);

   // signal(SIGALRM, signalHandler);
   // struct itimerval new_value, old_value;
   // new_value.it_value.tv_sec = 3;
   // new_value.it_value.tv_usec = 0;
   // new_value.it_interval.tv_sec = 1;
   // new_value.it_interval.tv_usec = 0;
   // setitimer(ITIMER_REAL, &new_value, &old_value);

   memset(&tmp_buf, '\0', sizeof(tmp_buf));
   int fd = open("a.txt", O_RDWR);

   while (1)
   {
      uint16_t num_bytes = read(serial_port, tmp_buf, sizeof(tmp_buf));
      if (num_bytes < 0)
      {
         printf("Error reading: %s", strerror(errno));
      }
      else if (num_bytes > 0)
      {
         printf("Read %d bytes. Received message: %s", num_bytes, tmp_buf);
         write(fd, tmp_buf, num_bytes);
         break;
      }
   }

   close(fd);
   return 0;
}

// void signalHandler(int signo)
// {
//    switch (signo)
//    {
//    case SIGALRM:
//       gettimeofday(&tv, NULL);
//       printf("millisecond: %ld\t", tv.tv_sec * 1000 + tv.tv_usec / 1000);
//       printf("tmp_size:%d\n", tmp_size);

//       timer_flag = 1;
//       tmp_size = 0;
//       break;
//    }
// }

uint8_t str2hex(uint8_t *in_buf, uint8_t *out_buf, uint16_t *out_size)
{
   uint8_t hith = 0;
   uint8_t low = 0;
   *out_size = 0;

   while (*in_buf != '\0')
   {
      if (*in_buf == ' ')
      {
         *in_buf++;
         // *out_buf++ = ' ';
         // *out_size += 1;
      }
      else
      {
         hith = *in_buf++;
         low = *in_buf++;
         if ((hith >= 'A') && (hith <= 'F'))
         {
            hith -= 'A';
            hith += 10u;
            hith <<= 4;
         }
         else if ((hith >= 'a') && (hith <= 'f'))
         {
            hith -= 'a';
            hith += 10u;
            hith <<= 4;
         }
         else if ((hith >= '0') && (hith <= '9'))
         {
            hith -= '0';
            // hith += 10u;
            hith <<= 4;
         }
         if ((low >= 'A') && (low <= 'F'))
         {
            low -= 'A';
            low += 10u;
         }
         else if ((low >= 'a') && (low <= 'f'))
         {
            low -= 'a';
            low += 10u;
         }
         else if ((low >= '0') && (low <= '9'))
         {
            low -= '0';
            // low += 10u;
         }
         *out_buf++ = ((hith & 0xF0) | (low & 0x0F));
         *out_size += 1;
      }
   }
   // *out_buf = '\0';
   // *out_size += 1;
}

int set_tty(int fd, int baud, int bits, int parity, int stop)
{
   struct termios tty;
   speed_t baud_rate;
   /* get current ttyions */

   /*	if (tcgetattr(fd, old_tio) != 0) {
    perror("tcgetattr() error!\n");
    return -1;
    }
    */
   bzero(&tty, sizeof(tty));
   tty.c_cflag |= (CLOCAL | CREAD);
   tty.c_cflag &= ~(CSIZE | PARENB);
   /* data bits */
   switch (bits)
   {
   case 5:
      tty.c_cflag |= CS5;
      break;
   case 6:
      tty.c_cflag |= CS6;
      break;
   case 7:
      tty.c_cflag |= CS7;
      break;
   case 8:
      tty.c_cflag |= CS8;
      break;
   default:
      printf("Unsupported data size!\n");
      return -1;
   }
   /* parity checking */
   switch (parity)
   {
   case 'o':
   case 'O':
      tty.c_cflag |= PARENB;
      tty.c_cflag |= PARODD;
      tty.c_iflag |= (INPCK | ISTRIP);
      break;
   case 'e':
   case 'E':
      tty.c_cflag |= PARENB;
      tty.c_cflag &= ~PARODD;
      tty.c_iflag |= (INPCK | ISTRIP);
      break;
   case 'n':
   case 'N':
      tty.c_cflag &= ~PARENB;
      tty.c_iflag &= ~INPCK;
      break;
   default:
      printf("Unsupported parity!\n");
      return -1;
   }
   /* baud rate */
   switch (baud)
   {
   case 4800:
      baud_rate = B4800;
      break;
   case 9600:
      baud_rate = B9600;
      break;
   case 19200:
      baud_rate = B19200;
      break;
   case 38400:
      baud_rate = B38400;
      break;
   case 57600:
      baud_rate = B57600;
      break;
   case 115200:
      baud_rate = B115200;
      break;
   case 230400:
      baud_rate = B230400;
      break;
   case 460800:
      baud_rate = B460800;
      break;
   case 921600:
      baud_rate = B921600;
      break;
   default:
      printf("Unsupported baudrate!\n");
      return -1;
   }
   cfsetispeed(&tty, baud_rate);
   cfsetospeed(&tty, baud_rate);
   /* stop bits */
   switch (stop)
   {
   case 1:
      tty.c_cflag &= ~CSTOPB;
      break;
   case 2:
      tty.c_cflag |= CSTOPB;
      break;
   default:
      printf("Unsupported stop bits\n");
      return -1;
   }
   tty.c_cc[VTIME] = 0;
   tty.c_cc[VMIN] = 0;

   /* raw mode */
   tty.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL | IXON);
   tty.c_oflag &= ~OPOST;
   tty.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);

   /* set new ttyions */
   tcflush(fd, TCIOFLUSH);
   if (tcsetattr(fd, TCSANOW, &tty) != 0)
   {
      printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
      return -1;
   }
   return 0;
}