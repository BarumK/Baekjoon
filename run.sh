#!/usr/bin/env bash
# ----------------------------------------------
# Shell-Agnostic 실행 스크립트 (Run Script)
# 사용법: ./run.sh [filename].[extension]
# - 지정된 파일을 찾고, 언어에 따라 실행
# - 실행 후 생성된 임시 파일(.class, 실행 파일 등)은 삭제
# ----------------------------------------------

# 오류 발생 시 즉시 종료
set -e

# ----------------------------------------------
# 1. 인자 확인: 입력 파일 인자가 없을 경우 사용법 출력
# ----------------------------------------------
if [ $# -eq 0 ]; then
    echo "Usage: $(basename "$0") [filename].[extension]"
    exit 1
fi

filename=$1

# ----------------------------------------------
# 2. 파일 확장자 추출 및 소문자로 변환
#    예: test.CPP → cpp
# ----------------------------------------------
ext="${filename##*.}"                                           # 확장자만 추출 (ex. cpp)
ext_lower=$(printf '%s' "$ext" | tr '[:upper:]' '[:lower:]')    # 소문자 변환

# ----------------------------------------------
# 3. 하위 디렉토리 포함 전체 탐색으로 파일 찾기
#    - 일치하는 첫 번째 파일 사용
#    - 찾은 파일이 없으면 오류 출력
# ----------------------------------------------
found=""
while IFS= read -r -d '' f; do
    found=$f
    break
done < <(find . -type f -name "$filename" -print0)

if [ -z "$found" ]; then
    echo "❌ File Not Found: $filename"
    exit 1
fi

# ----------------------------------------------
# 4. 파일 경로를 절대 경로로 변환
#    - cleanup 처리 시 정확한 경로 확보 목적
# ----------------------------------------------
found="${found#./}"     # ./ 제거
found="$(pwd)/$found"   # 절대 경로로 변환

# ----------------------------------------------
# 5. 종료 시 임시 파일 정리 함수 등록 (trap)
#    - 컴파일된 실행 파일 또는 .class 파일 삭제
# ----------------------------------------------
exe=""  # 실행 파일 이름 저장용
dir=""  # 자바 파일의 디렉토리 경로 저장용
cleanup(){
    case "$ext_lower" in
        c|cc|cpp|cxx|c\+\+)
            [ -n "$exe" ] && rm -f "$exe"
            ;;
        java)
            [ -n "$dir" ] && rm -f "$dir"/*.class
            ;;
    esac
}
trap cleanup EXIT # 스크립트 종료 시 cleanup 자동 실행

# ----------------------------------------------
# 6. 확장자별 실행 처리
#    - Python: 인터프리터 실행
#    - C/C++: 컴파일 후 실행
#    - Java: javac로 컴파일 → class 이름 자동 탐지 → 실행
# ----------------------------------------------
case "$ext_lower" in
    py)
        python3 "$found"
        ;;

    c)
        exe="${filename%.*}"
        gcc -std=c17 -O2 -o "$exe" "$found"
        ./"$exe"
        ;;

    cc|cpp|cxx|c\+\+)
        exe="${filename%.*}"
        g++ -std=c++17 -O2 -o "$exe" "$found"
        ./"$exe"
        ;;

    java)
        dir=$(dirname "$found")                 # 디렉토리 경로
        base=$(basename "$found")               # 파일명만 추출
        old_pwd=$(pwd)                          # 현재 디렉토리 저장
        cd "$dir"                               # 파일 위치로 이동
        javac "$base"                           # 컴파일
        
        # Main 클래스 이름 자동 탐지 (없으면 Main으로 가정)
        mainclass=$(grep -E 'class[[:space:]]+' "$base" \
                    | sed -E 's/.*class[[:space:]]+([A-Za-z_][A-Za-z0-9_]*).*/\1/' \
                    | head -n1)

        [ -z "$mainclass" ] && mainclass="Main" # 기본값은 Main
        java -cp . "$mainclass"                 # 실행
        cd "$old_pwd"                           # 원래 위치로 복귀
        ;;

    *)
        echo "Unsupported extension: $ext_lower"
        exit 1
        ;;
esac

exit 0