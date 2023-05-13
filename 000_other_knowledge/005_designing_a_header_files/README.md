## 헤더파일의 디자인과 활용
헤더파일의 이해를 위해, **`#include`** 지시자의 의미에 대해 알아보도록 하겠다. 다음 예시코드를 한번 봐 보자.

#### [ex_header_file01.h]
```c
{
  printf("Hello World!");
```
#### [ex_header_file02.h]
```c
  printf("Hello Yoonsik!");
}
```
#### [example01.c]
```c
#include <stdio.h>

int main()
#include "ex_header_file01.h"
#include "ex_header_file02.h"
```
해당 코드내에 **`#include`** 지시자를 사용한 부분의 의미를 설명하면 다음과 같다. 

**`#include "ex_header_file01.h"`** - *이 부분에 해당 파일 (`ex_header_file01.h`) 에 저장된 내용을 포함해주세요.*<br>
**`#include "ex_header_file02.h"`** - *이 부분에 해당 파일 (`ex_header_file02.h`) 에 저장된 내용을 포함해주세요.*<br><br>
그렇다. **`#include`** 지시자는 이름과 같이 해당 지시자의 위치에 파일에 저장된 내용을 포함 시켜주는 용도로 사용한다. 그리고, 이 **`#include`** 지시어의 내용은 선행처리기에 전달되어 컴파일 전에 수행되게 된다.<br><br>
위 코드의 선행처리가 이루어지면 다음과 같은 코드가 완성된다. 
#### [example01.c]
```c
#include <stdio.h>

int main()
{
  printf("Hello World!\n");
  printf("Hello Yoonsik!");
}
```
이렇게 완성된 코드를 보면 다음과 같은 이해가 가능하다. **"`#include` 지시어가 있는 자리에 지정한 헤더파일의 내용이 포함되는구나!"**<br><br>

### 헤더파일을 include 하는 두 가지 방법
