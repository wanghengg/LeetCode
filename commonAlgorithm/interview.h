#ifndef LEETCODE_INTERVIEW_H
#define LEETCODE_INTERVIEW_H

void *memcpy(void* dst, const void* src, unsigned int count) {
    void *ret = dst;
    while (count--) {
        *(char *)dst = *(char *)src;   // 不能直接对void解引用
        dst = (char *)dst + 1;  // 不能直接对void指针加1
        src = (char *)src + 1;
    }
    return ret;
}

void *memmove(void* dst, const void* src, unsigned int count) {
    void *ret = dst;
    if (dst < src || (char *)dst >= (char *)src + count) {  // 没有重叠或者重叠但是不影响
        while (count--) {
            *(char *)dst = *(char *)src;
            dst = (char *)dst + 1;
            src = (char *)src + 1;
        }
    } else {
        dst = (char *)dst + count - 1;
        src = (char *)src + count - 1;
        while (count--) {
            *(char *)dst = *(char *)src;
            dst = (char *)dst - 1;
            src = (char *)src - 1;
        }
    }
    return ret;
}

int atoi(const char* p) {

}
#endif //LEETCODE_INTERVIEW_H
