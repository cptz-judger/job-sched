import json
import sys


def same(std: str, out: str) -> bool:
    return std.strip() == out.strip()


def main():
    std_file_name = sys.argv[1]
    run_out_err = json.loads(input())
    if run_out_err['err'] != '':
        print('在 stderr 中检测到输出')
        exit(1)
    with open(std_file_name, 'r') as f:
        std = f.read()
    if same(std, run_out_err['out']):
        print('完全正确')
        exit(0)
    else:
        print('输出错误')
        exit(2)


if __name__ == '__main__':
    main()
