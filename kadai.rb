# テストの点数データ
science_scores = [65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 25, 85, 46, 42, 78, 62, 84, 70]
english_scores = [44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84]

# 平均点の計算
def calculate_average(scores)
  total = scores.sum
  average = total.to_f / scores.length
  return average
end

# 標準偏差の計算
def calculate_standard_deviation(scores, average)
  squared_diff_sum = scores.map { |score| (score - average) ** 2 }.sum
  variance = squared_diff_sum / scores.length
  standard_deviation = Math.sqrt(variance)
  return standard_deviation
end

# 合計点の計算
def calculate_total(scores)
  return scores.sum
end

# 偏差値の計算
def calculate_z_scores(scores)
  average = calculate_average(scores)
  standard_deviation = calculate_standard_deviation(scores, average)
  z_scores = scores.map { |score| (score - average) / standard_deviation * 10 + 50 }
  return z_scores
end

# 点数の高い順に並べ替え
def sort_scores_descending(scores)
  return scores.sort.reverse
end

# 理科の平均点、標準偏差、合計点の計算
science_average = calculate_average(science_scores)
science_standard_deviation = calculate_standard_deviation(science_scores, science_average)
science_total = calculate_total(science_scores)

# 理科の偏差値の計算
science_z_scores = calculate_z_scores(science_scores)

# 理科の点数の高い順に並べ替え
sorted_science_scores = sort_scores_descending(science_scores)

# 英語の平均点、標準偏差、合計点の計算
english_average = calculate_average(english_scores)
english_standard_deviation = calculate_standard_deviation(english_scores, english_average)
english_total = calculate_total(english_scores)

# 英語の偏差値の計算
english_z_scores = calculate_z_scores(english_scores)

# 英語の点数の高い順に並べ替え
sorted_english_scores = sort_scores_descending(english_scores)

# 結果の出力
puts "理科の平均点: #{science_average}"
puts "理科の標準偏差: #{science_standard_deviation}"
puts "理科の合計点: #{science_total}"
puts "理科の偏差値: #{science_z_scores}"
puts "理科の点数の高い順: #{sorted_science_scores}"

puts "\n"

puts "英語の平均点: #{english_average}"
puts "英語の標準偏差: #{english_standard_deviation}"
puts "英語の合計点: #{english_total}"
puts "英語の偏差値: #{english_z_scores}"
puts "英語の点数の高い順: #{sorted_english_scores}"

