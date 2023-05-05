#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char ip_address[16];
    int first_octet, second_octet, third_octet, fourth_octet;
    int network_id, host_id;
    char ip_class;

    printf("Enter an IPV4 address in dotted decimal notation: ");
    scanf("%s", ip_address);

    sscanf(ip_address, "%d.%d.%d.%d", &first_octet, &second_octet, &third_octet, &fourth_octet);

    if (first_octet >= 1 && first_octet <= 126) {
        ip_class = 'A';
        network_id = first_octet;
        host_id = (second_octet << 16) | (third_octet << 8) | fourth_octet;
    } else if (first_octet >= 128 && first_octet <= 191) {
        ip_class = 'B';
        network_id = (first_octet << 8) | second_octet;
        host_id = (third_octet << 8) | fourth_octet;
    } else if (first_octet >= 192 && first_octet <= 223) {
        ip_class = 'C';
        network_id = (first_octet << 16) | (second_octet << 8) | third_octet;
        host_id = fourth_octet;
    } else if (first_octet >= 224 && first_octet <= 239) {
        ip_class = 'D';
        network_id = 0;
        host_id = 0;
    } else if (first_octet >= 240 && first_octet <= 255) {
        ip_class = 'E';
        network_id = 0;
        host_id = 0;
    } else {
        printf("Invalid IP address.\n");
        return 1;
    }

    printf("IP address class: %c\n", ip_class);
    printf("Network ID: %d\n", network_id);
    printf("Host ID: %d\n", host_id);

    return 0;
}
