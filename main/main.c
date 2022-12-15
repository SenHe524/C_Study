#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define __weak __attribute__((weak))

typedef struct
{
    int *data;
    int maxsize;
    int len;
} List;


void Init_List(List *L, int size);
void IncreaseSize(List *L, int len);
void SetList(List *L, int i, int data);
void PrintfList(List *L);

typedef union 
{
    int data_int32;
    unsigned char data8[4];
}union_int32;
union_int32 _32_buf[2];
typedef struct
{
    int data;
    int maxsize;
    int len;
    union_int32 aa;
} _asm;
typedef struct
{
	float accel_x;			/*uinit: m/s2*/
	float accel_y;
	float accel_z;

	float angle_x;			/*uinit: ° (deg)/s*/
	float angle_y;
	float angle_z;

	float mag_x;			/*uinit: 归一化值*/
	float mag_y;
	float mag_z;

	float raw_mag_x;		/*uinit: mGauss*/
	float raw_mag_y;
	float raw_mag_z;
	
	float pitch;			/*uinit: ° (deg)*/
	float roll;
	float yaw;
	
	float quaternion_data0;
	float quaternion_data1;	
	float quaternion_data2;
	float quaternion_data3;
}protocol_info_t;

int main(void)
{
    protocol_info_t* data;
    data->accel_x = 546.35f;
    data->accel_y = 546.35f;
    data->accel_z = 546.35f;
    data->angle_x = 864.41f;
    data->angle_y = 864.41f;
    data->angle_z = 864.41f;
    printf("%d\n",sizeof(*data));
    // printf("%d\n",sizeof(a));
    printf("%p\n",&(data->accel_x));
    printf("%p\n",data);
    printf("%p\n",&(data->accel_x)+1);
    printf("%p\n",&(data->accel_y));
    printf("%p\n",&(data->accel_x)+8);
    printf("%p\n",&(data->mag_z));
    printf("%p\n",&(data->accel_x)+18);
    printf("%p\n",&(data->quaternion_data3));
    for(int i = 0; i < 19; i++)
    {
        printf("%p\n",&(data->accel_x)+i);
        printf("%f\n",(&(data->accel_x)+i)[0]);
    }
    // printf("%p\n",&a.maxsize);
    // printf("%p\n",&a.len);
    // printf("\n");
    // printf("%p\n",&a.aa);
    // printf("%p\n",&a.aa.data_int32);
    // printf("%p\n",a.aa.data8);
    system("pause");
    return 0;
}

void Init_List(List *L, int size)
{
    L->data = (int *)malloc(sizeof(int) * size);
    for(int i = 0; i < L->maxsize; i++)
    {
        L->data[i] = 0;
    }
    L->len = 0;
    L->maxsize = size;
}

void IncreaseSize(List *L, int len)
{
    int *p = L->data;
    L->data = (int *)malloc(sizeof(int) * (L->maxsize + len));
    for(int i = 0; i < L->len; i++)
    {
        L->data[i] = p[i];
    }
    L->maxsize = L->maxsize + len;
    for(int i = L->len; i < L->maxsize; i++)
    {
        L->data[i] = 0;
    }
    free(p);
}

void SetList(List *L, int i, int data)
{
    if(i <= L->maxsize)
    {
        L->data[i-1] = data;
        L->len < i? L->len = i:0;
    }
    else{
        printf("����λ�ô���\n");
    }
}

void PrintfList(List *L)
{
    for(int i = 0; i < L->len; i++)
    {
        printf("��%dλԪ��Ϊ%d\n",i+1, L->data[i]);
    }
    printf("\n");
}