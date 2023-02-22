#include <stdio.h>

int main()
{
  int count = 0;
  int hp=0, mp=0, strikingPower=0, defensesivePower=0;
  int value1=0, value2=0, value3=0, value4=0;
  int power=0;

  scanf("%d", &count);

  for(int i=0; i<count; i++){
    scanf("%d %d %d %d %d %d %d %d", &hp, &mp, &strikingPower, &defensesivePower, &value1, &value2, &value3, &value4);

    if(hp+value1 < 1)
      hp = 1 - value1;
    if(mp+value2 < 1)
      mp = 1 - value2;
    if(strikingPower+value3 < 0)
      strikingPower = -1 * value3;

    power = (hp+value1)*1 + (mp+value2)*5 + (strikingPower+value3)*2 + (defensesivePower+value4)*2;

    printf("%d\n", power);
  }

  return 0;
}