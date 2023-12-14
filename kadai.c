#include <stdio.h>
#include <math.h>

// テストの点数データ
int science_scores[] = {65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 25, 85, 46, 42, 78, 62, 84, 70};
int english_scores[] = {44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84};

// 配列の要素数
int num_students = sizeof(science_scores) / sizeof(science_scores[0]);

// 平均点の計算
double calculate_average(int scores[]) {
    int total = 0;
    for (int i = 0; i < num_students; i++) {
        total += scores[i];
    }
    return (double)total / num_students;
}

// 標準偏差の計算
double calculate_standard_deviation(int scores[], double average) {
    double squared_diff_sum = 0;
    for (int i = 0; i < num_students; i++) {
        squared_diff_sum += pow(scores[i] - average, 2);
    }
    double variance = squared_diff_sum / num_students;
    return sqrt(variance);
}

// 合計点の計算
int calculate_total(int scores[]) {
    int total = 0;
    for (int i = 0; i < num_students; i++) {
        total += scores[i];
    }
    return total;
}

// 偏差値の計算
void calculate_z_scores(int scores[], double z_scores[]) {
    double average = calculate_average(scores);
    double standard_deviation = calculate_standard_deviation(scores, average);
    for (int i = 0; i < num_students; i++) {
        z_scores[i] = (scores[i] - average) / standard_deviation * 10 + 50;
    }
}

// 点数の高い順に並べ替え
void sort_scores_descending(int scores[]) {
    for (int i = 0; i < num_students - 1; i++) {
        for (int j = 0; j < num_students - i - 1; j++) {
            if (scores[j] < scores[j + 1]) {
                // 交換
                int temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;
            }
        }
    }
}

int main() {
    // 理科の平均点、標準偏差、合計点の計算
    double science_average = calculate_average(science_scores);
    double science_standard_deviation = calculate_standard_deviation(science_scores, science_average);
    int science_total = calculate_total(science_scores);

    // 理科の偏差値の計算
    double science_z_scores[num_students];
    calculate_z_scores(science_scores, science_z_scores);

    // 理科の点数の高い順に並べ替え
    sort_scores_descending(science_scores);

    // 英語の平均点、標準偏差、合計点の計算
    double english_average = calculate_average(english_scores);
    double english_standard_deviation = calculate_standard_deviation(english_scores, english_average);
    int english_total = calculate_total(english_scores);

    // 英語の偏差値の計算
    double english_z_scores[num_students];
    calculate_z_scores(english_scores, english_z_scores);

    // 英語の点数の高い順に並べ替え
    sort_scores_descending(english_scores);

    // 結果の出力
    printf("理科の平均点: %.2f\n", science_average);
    printf("理科の標準偏差: %.2f\n", science_standard_deviation);
    printf("理科の合計点: %d\n", science_total);
    printf("理科の偏差値: ");
    for (int i = 0; i < num_students; i++) {
        printf("%.2f ", science_z_scores[i]);
    }
    printf("\n");
    printf("理科の点数の高い順: ");
    for (int i = 0; i < num_students; i++) {
        printf("%d ", science_scores[i]);
    }
    printf("\n\n");

    printf("英語の平均点: %.2f\n", english_average);
    printf("英語の標準偏差: %.2f\n", english_standard_deviation);
    printf("英語の合計点: %d\n", english_total);
    printf("英語の偏差値: ");
    for (int i = 0; i < num_students; i++) {
        printf("%.2f ", english_z_scores[i]);
    }
    printf("\n");
    printf("英語の点数の高い順: ");
    for (int i = 0; i < num_students; i++) {
        printf("%d ", english_scores[i]);
    }
    printf("\n");

    return 0;
}
