# GNU/리눅스 (리눅스 운영체제)
**GNU/리눅스**는 운영체제이다. 운영체제란, 여러가지 프로그램의 모음으로, 이 프로그램을 이용하여 컴퓨터를 사용하고,<br>
다른 프로그램을 실행하기도 한다.<br>

운영체제는 컴퓨터에 필요한 여러가지 기초적인 프로그램으로 이루어져 있으며, 우리는 해당 프로그램을 통해 컴퓨터와<br>
의사소통 하고, 컴퓨터에 지시를 내린다. 예를 들어, 하드디스크, 프린터, 테이프로 데이터를 보내거나 데이터를 읽어들이며,<br>
메모리 사용을 제어하고 다른 프로그램을 실행한다. <br>

운영체제의 핵심이 되는 가장 중요한 부분이 바로 커널인데, GNU/리눅스 시스템에서 '리눅스'는 커널 부분에 해당되고,<br>
커널(리눅스)를 제외한 시스템의 나머지 부분은 기타 프로그램으로 구성되며, GNU 프로젝트가 많은 부분을 개발하였다.<br>

우리가 흔히 '리눅스'라고 칭하는 운영체제는 리눅스라는 커널과 GNU 프로젝트가 많은 부분 개발한 기타 프로그램으로<br>
구성된 형태를 띈다. 리눅스 커널 자체만으로는 운영체제를 구성할 수는 없기 때문에, 해당 운영체제를 GNU/리눅스 라는<br>
이름으로 사용하기도 한다.<br>
(GNU/리눅스 운영체제의 커널을 의미하는 '리눅스'와, 리눅스 커널 + GNU 프로젝트의 기타 프로그램으로 이루어진<br>
GNU/리눅스 운영체제를 의미하는 '리눅스'를 혼동하지 않도록 하자)<br>
<br>
## GNU 프로젝트
![스크린샷(2)](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/07f1b9e1-966a-440e-b8cd-2ccf188af167)<br>

**GNU 프로젝트**는 리처드 스톨먼(Richard Matthew Stallman)의 주도하에, 1984년 시작된 오픈 소스 소프트웨어 프로젝트이다.<br>
여기서, 오픈 소스 소프트웨어(Open source software, OSS)란 소스 코드를 공개해, 누구나 특별한 제한 없이<br>
그 코드를 보고 사용할 수 있는 오픈소스 사용권(라이선스)을 만족하는 소프트웨어를 의미한다.<br>

GNU 프로젝트의 목적은 자유롭게 사용할 수 있는 소프트웨어로 구성된 유닉스(Unix) 운영체제를 만드는 것이다.<br>
그리고, 사용자가 운영체제를 개선할 수 있도록 소스코드까지 공개하는 것이 목표였다. <br>
하지만, 운영체제의 핵심기능을 담당하는 커널(컴퓨터 운영체제의 핵심이 되는 컴퓨터 프로그램으로, 시스템의 <br>
모든 것을 완전히 제어한다)은 끝끝내 완성하지 못하였다.<br>

결국 자동차의 엔진에 비견되는 커널이 빠진 채, 차체와 내장재는 모두 만들어낸 꼴이 된 것이다.<br>
엔진이 빠진 자동차가 굴러갈 수 없듯이, 커널이 빠진 운영체제 또한 제대로 동작하지 않았을 것이다. <br>

## 리눅스 커널
![스크린샷(2)](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/ea9cad97-a3db-497f-bba3-b243489b1b85)<br>

**리눅스 커널**은 리누스 토발즈(Linus Benedict Torbals)가 개발하여, 1991년 9월 17일 소스코드와 함께 공개되었다. <br>
리누스 토발즈가 리눅스 커널을 개발하게된 데에는, 다음과 같은 배경이 있었다.<br>

당시 리누스 토발즈는 핀란드 헬싱키에 위치한 헬싱키 공과 대학의 대학원생으로 있었는데, 그때 교육용으로 사용하던 운영체제인<br>
Minix의 기능이 풍족하지 않다고 느꼈다고 한다.<br>
하지만, 이 minix운영체제를 만든 타네바움(Andrew Tanenbaum)이 다른사람이 함부로 이 minix를 개조하지 못하도록 제한을 두었기<br>
때문에 리누스 토발즈는 이 불만을 해결할 방법이 없었다.<br>

결국, 직접 운영체제를 개발하기로 마음먹고, 운영체제의 핵심 기능을 담당하는 커널을 만들었다. 이것이 바로 GNU/리눅스<br>
(흔히, 리눅스라고 부르는 운영체제)의 커널부분을 담당하는 리눅스가 된다.<br> 

리누스 토발즈는 이 리눅스를 누구나 사용할 수 있도록 소스코드를 포함하여 1991년 9월 17일 세상에 공개한다.<br>
<br>

# GCC(GNU Compiler Collection)
![스크린샷(4)](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/ec271272-40c5-4a51-bd66-2d6a485c71c8)<br>

GCC(CNU Compiler Collection)은 말 그대로, GNU 프로젝트의 컴파일러 컬렉션이다.<br>
GNU 프로젝트를 주도한 리처드 스톨먼(Richard Matthew Stallman)에 의해 1987년 만들어졌다. <br>

유닉스/리눅스 계열 플랫폼의 사실상 표준 컴파일러로, C(gcc), C++(g++), Objective-C(gobjc),<br>
Fortran(gfortran), Ada(gnat), Go(gccgo), D(gdc)이다. Java(gcj)는 GCC 7.1버전부터 지원이 중단되었다.<br>

## GCC를 이용한 컴파일
이제, 이 gcc를 이용한 컴파일을 하는 방법에 대해 정리해 보도록 하겠다.<br>

먼저, 사용중인 컴퓨터에 gcc가 깔려 있는지 확인하기 위해선 다음 명령을 이용하여 gcc설치 여부와 설치된 gcc의<br>
버전을 확인해야 한다.<br>
```c
gcc --version
```
해당 명령을 사용하면, gcc가 컴퓨터에 설치되어 있는 경우, 아래와 같이, 설치되어 있는 gcc의 버전을 확인해 볼 수 있다.<br>

![스크린샷(6)](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/6fe015ce-48b1-466c-83d9-7a5007b4edb3)<br>

### GCC의 컴파일 과정
gcc의 컴파일 과정은 아래 그림과 같이 나타낼 수 있다. <br>

![ㅎㅊㅊzjavkdfl rhkwjd](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/506bc70f-7465-4525-904f-f33b69b65fb3)<br>

- **선행처리(preprocessig):** 선행처리기(preprocessor)가 사용자가 C언어로 작성한 소스코드(.c)의 `#include`, `#define`과<br>
조건부 컴파일을 위한 매크로 등과 같은 선행처리 지시자를 해석해준다.<br>
이러한 선행처리가 끝이 나면, `i` 확장자를 가진 파일(.i)이 생성된다. 이제, 본격적으로 C언어를 기계어로 변환하기 시작한다.<br>

- **컴파일(Compile):** 컴파일러(compiler)가 high level의 언어들(`C`나 `C++`과 같은 프로그래밍 언어)을 low level 언어인<br>
어셈블리어(.s)로 변환해준다.<br>
즉, 인간이 이해하기 쉬운 high level 언어를 컴퓨터가 이해하기 쉬운 low level 언어인 어셈블리어로 번역하는 것과 같다.<br>
이러한 컴파일 과정이 완료되면, 기계어와 가장 유사한 상태인 어셈블리어로 변환된 `s` 확장자를 가진 파일(.s)이 생성된다.<br>

- **어셈블리(assembly):** 어셈블러(assembler)가 어셈블리어 파일(.s)을 기계어 형태의 오브젝트 파일(.o)로 변환해준다.<br>
해당 과정을 통해, 2진수로 이루어진 기계어로 된 파일(.o)이 생성된다. 확장자는 `o`이다.<br>

- **링크(link):** 링커(linker)가 생성된 목적파일들을 묶어서 실행파일을 생성한다. 선행처리에서 링크과정을 통해 생성된 실행파일(.exe)은 <br>
`exe`확장자를 가진다.<br>
이 `exe`확장자는 Executable의 약자로, 일반적인 파일 확장자로 컴퓨터 프로그램의 실행 파일을 가리킨다.<br>
오픈VMS, 도스, 마이크로소프트 윈도우, 리엑트오에스, OS/2 운영 체제에서 사용할 수 있다.<br>
<br>
이렇게, GCC의 컴파일 과정을 보면 알 수 있듯이, 선행처리에서 어셈블리 까지의 과정에서 중간 파일들이 생성된다.<br>
이 중간 파일들은 최종 링크과정을 통해 실행파일이 생성되고 나면, 모두 삭제된다.<br>

이때, `gcc`명령어 옵션들을 통해 GCC컴파일 과정 중, 중간에 생성되는 파일들을 지우지 않고 디렉터리에 저장 하거나,<br>
원중간 파일만 생성해 볼 수도 있다.<br>

### `gcc`명령어를 이용한 컴파일
`gcc`명령어는 앞에 `gcc`를 써서 호출이 가능하다.<br>

먼저, `gcc`명령어에는 어떤 옵션들이 있는지 한번 알아 보도록 하겠다.<br>
다음은 `gcc`명령어의 옵션들을 정리해놓은 표이다.<br> 

|`gcc`명령어 옵션|설명|
|:-----:|:---|
|**`-E`**|전처리 과정을 화면에 결과로 출력한다.|
|**`-S`**|어셈블리 파일(.s)만 생성하고 컴파일을 멈춘다.|
|**`-c`**|오브젝트 파일(.o)만 생성하고 컴파일을 멈춘다.|
|**`-v`**|컴파일 과정을 화면에 자세히 출력한다.|
|**`-o<file이름>`**|출력을 이름을 지정한 파일에 둔다. gcc 컴파일을 통해 실행파일의 이름을 지정해주는 용도로 사용하기도 한다.|  
|**`-save-temps`**|컴파일 과정중, 생성되는 파일인 전처리 파일(.i), 어셈블리 파일(.s), 오브젝트 파일(.o)을 지우지 않고<br> 디렉터리에 저장한다.|

이때, 이러한 `gcc`명령어를 이용하여 여러개의 소스파일과 헤더파일로 이루어진 프로그램을 컴파일 할 시,<br>
주의할 점이 존재한다.<br>

### `undefined reference to <Function>` 에러
여러개의 소스파일로 이루어진 프로그램을 컴파일 할 때 우선순위에 따라 소스파일들을 컴파일해주지 않았기 때문에 발생하는 에러이다.<br>
분명, 헤더파일 `A.h`에는 함수 `a`가 선언되어 있는데, 정작 `a`라는 함수에 대한 정의를 찾지 못하였을 때 해당 에러가 발생된다.<br>
이때, *"어? 나는 분명, 소스파일 `A.c`에 함수 `a`에 대한 정의를 해 놓았는데 왜이러지?"* 하는 의문이 들 수 있다.<br>

소스파일에 헤더파일에 선언되어있는 함수들을 정의해두었는데도 불구하고, `undefined reference to <Function>` 에러가 뜨는 원인은<br>
해당 파일들을 컴파일하는 IDE나, `gcc`에서 이 순서를 반대로 컴파일 했기 때문이다.<br>

이러한 에러를 해결하기 위해서는 우리가 직접 `gcc`명령어를 이용하여 우선순위에 따라 소스파일들을 컴파일 해 주어야 한다.<br>
소스파일의 우선순위를 결정하는 기준은 다음과 같다.<br>

> **의존성이 강한, 즉, 다른 헤더 파일과 소스파일에서 정의된 함수나 변수들을 많이 가져다 쓰는 파일을 가장 앞으로 보내야 한다.**

보통은 `main` 함수가 있는 파일이 가장 많이 함수들과 변수들을 다른 헤더 파일들과 c파일에서 가져다 사용하기 때문에, 의존성이<br>
제일 높다. 때문에, `gcc` 명령어로 여러개의 소스파일로 이루어진 프로그램을 컴파일 할 시,`main`함수가 있는 파일을 명령어의 가장<br>
앞 부분으로 보내주어야 한다.<br>

### `gcc`명령어를 이용한 컴파일 실습
`gcc`를 이용하여 컴파일할 때 사용하는 명령어는 다음과 같다.<br>

```
gcc -o [컴파일을 통해 생성할 실행파일 이름] [main함수가 들어있는 c파일(.c)] [연결된 c파일(.c)]
// 보통은 생성할 실행파일의 이름을 main함수가 들어있는 C파일의 이름과 동일하게 지정함
```

그럼 이제, 여러개의 소스파일로 이루어진 간단한 연산 프로그램인 `siple_calculator`를 컴파일 하여 실행파일을 생성해 보도록 하겠다.<br>

![스크린샷(3)](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/136039e8-fead-4e29-9157-6c195fad0092)<br>

##### [basicArith_copy0.h]
```c
#define PI 3.1415

double Add (double num1, double num2);
double Min (double num1, double num2);
double Mul (double num1, double num2);
double Dib (double num1, double num2);
```

##### [basicArith_copy0.c]
```c
double Add (double num1, double num2) {
	return num1 + num2;
}

double Min (double num1, double num2) {
	if(num1 > num2) 
		return num1 - num2;
	else
		return num2 - num1;
}

double Mul (double num1, double num2) {
	return num1 * num2;
}

double Div (double num1, double num2) {
	return num1 / num2;
}
```

##### [simple_calculator.c]
```c
#include <stdio.h>
#include "basicArith_copy0.h"

int main(void)
{
	double num = Add(1.5, 2.3); 
	
	printf("%g\n", num);
	
	return 0;
}
```
<br>

이 `simiple_calculator`을 이루는 소스파일들 중, 가장 의존성이 높은(함수 혹은 변수들을 다른 소스파일이나 헤더파일에서 많이 가져다 쓰는)<br>
소스파일은 바로, `main`함수를 포함하고 있는 `simple_calculator.c`파일이다.<br>

해당 소스파일을 `gcc`명령어의 맨 앞에 보내어 컴파일 명령어를 작성하면, 다음과 같다.<br>

```
gcc -o simple_calculator simple_calculator.c basicArith_copy0.c
```

이렇게 만들어진 명령어를 실행시키면, `-o` 명령어 옵션으로 지정해준 `simple_calculator`라는 이름의 실행파일이 생성된다.<br>

![스크린샷(5)](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/57314d20-1621-4898-8b4a-d2847dc4f8f8)<br>

![스크린샷(7)](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/dd0c77f6-1e8c-4556-a096-9e2c6096aef4)<br>

이렇게 만들어진 `simple_calculator` 실행파일을 실행시키기 위해선, 해당 실행파일이 저장되어 있는 위치에서 `./simple_calculator`<br>
명령을 이용하여 실행이 가능하다.<br>

![스크린샷(10)](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/b7139746-5e1e-4895-84c3-479f070bfd78)










