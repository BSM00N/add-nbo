# 컴파일러 변수
CC = gcc
# 컴파일러 옵션
CFLAGS = -Wall -Wextra -Werror

# 기본 규칙 (all이라는 명령어를 사용할 경우 addnbo 규칙 호출)
all: addnbo

# addnbo 실행 파일 생성 규칙
addnbo:
	gcc -o add-nbo addnbo.c

# 정리 규칙 (빌드된 파일 정리)
clean:
	rm -f add-nbo
