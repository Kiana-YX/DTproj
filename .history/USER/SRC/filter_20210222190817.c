#include "filter.h"
/*************************************************************/
IIR_struct my_IIR;
/*************************************************************/


void IIR_init(IIR_struct *IIR_flt) //低通滤波初始化
{
    //TODO:根据matlab测试效果,应该要调整a
    //在excel粗略看越大越平滑
    IIR_flt->a=0.98;
    IIR_flt->distance[0]=0;
}

///* Yn=qXn+(1-q)Yn-1 */
//若采样间隔δt足够小,则滤波器的截止频率为:f=q/(2πδt)
//FIXME:ADS芯片读取速度很快,能不能直接用读取到的数据,用多任务类型一直读取?定时器里面只进行CAN的发送
float IIR_filter(IIR_struct *IIR_flt, double input) //一阶滞后低通滤波
{
//    IIR_flt->now = (1 - IIR_flt->a) * IIR_flt->last + IIR_flt->a * input; //这一时刻滤波后的值
//    IIR_flt->last = IIR_flt->now;                                         //上一时刻滤波后的值

//    return IIR_flt->now;
    rerurn 0;
}
