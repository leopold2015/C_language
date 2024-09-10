void __f(void)
{

    printf("__f\n");
}

void f() __attribute__((alias("__f")));

int main()
{

    f();  // 输出：__f
    return 0;
}