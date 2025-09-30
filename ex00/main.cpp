#include "Bureaucrat.hpp"
#include <iostream>

// ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

void printHeader(const std::string& title)
{
    std::cout << "\n" << BOLD << CYAN << "=== " << title << " ===" << RESET << std::endl;
}

void printTest(const std::string& testName)
{
    std::cout << "\n" << YELLOW << testName << ":" << RESET << std::endl;
}

void printSuccess(const std::string& message)
{
    std::cout << GREEN << message << RESET << std::endl;
}

void printError(const std::string& message)
{
    std::cout << RED << message << RESET << std::endl;
}

void printInfo(const std::string& message)
{
    std::cout << BLUE << message << RESET << std::endl;
}

void printProgress(int current, int total)
{
    std::cout << "\n" << CYAN << "Progress: [" << current << "/" << total << "] ";
    for (int i = 0; i < current; i++) std::cout << "█";
    for (int i = current; i < total; i++) std::cout << "░";
    std::cout << " " << (current * 100 / total) << "%" << RESET << std::endl;
}

void printTestSummary(int passed, int failed, int total)
{
    std::cout << "\n" << BOLD << "TEST SUMMARY" << RESET << std::endl;
    std::cout << GREEN << "Passed: " << passed << RESET << std::endl;
    std::cout << RED << "Failed: " << failed << RESET << std::endl;
    std::cout << BLUE << "Total:  " << total << RESET << std::endl;
    std::cout << "Success Rate: " << (passed * 100 / total) << "%" << std::endl;
}

int main()
{
    int passed = 0, failed = 0, total = 8;
    
    printHeader("Bureaucrat Class Test Suite");
    
    // Real-world scenario explanation
    printInfo("実世界のシナリオ:");
    printInfo("   政府機関の150段階の権限システムを想像してください");
    printInfo("   等級1: 大統領（最高権限）");
    printInfo("   等級50: 部長（中級権限）");
    printInfo("   等級150: 新人職員（最低権限）");
    printInfo("   昇進: より高い権限へ（数値が小さくなる）");
    printInfo("   降格: より低い権限へ（数値が大きくなる）");
    
    // Grade system explanation
    printInfo("等級システムの説明:");
    printInfo("   等級1   = 最高権限（大統領レベル）");
    printInfo("   等級50  = 中級権限（部長レベル）");
    printInfo("   等級150 = 最低権限（新人レベル）");
    printInfo("   昇進 = 等級番号が減少（3 → 2）");
    printInfo("   降格 = 等級番号が増加（148 → 149）");
    
    // Test 1: Normal construction
    printProgress(1, total);
    printTest("Constructor Validation Test");
    printInfo("目的: 有効な等級が受け入れられることを確認");
    printInfo("テスト内容: 等級50（有効範囲[1-150]内）");
    printInfo("期待結果: Bureaucratが正常に作成される");
    try
    {
        Bureaucrat b1("Alice", 50);
        printSuccess("実際の結果: " + std::string(b1.getName()) + " (等級: " + std::to_string(b1.getGrade()) + ")");
        printSuccess("結果: テスト成功 - コンストラクタが正常に動作");
        passed++;
    }
    catch (const std::exception& e)
    {
        printError("Bureaucratの作成に失敗: " + std::string(e.what()));
        printError("結果: テスト失敗 - コンストラクタは成功すべき");
        failed++;
    }

    // Test 2: Grade too high (0)
    printProgress(2, total);
    printTest("Invalid Grade - Too High");
    printInfo("目的: 無効な等級が拒否されることを確認");
    printInfo("テスト内容: 等級0（最小値1を下回る）");
    printInfo("期待結果: GradeTooHighExceptionが投げられる");
    try
    {
        Bureaucrat b2("Bob", 0);
        printError("エラー: 無効な等級でBureaucratが作成されました！");
        printError("結果: テスト失敗 - 例外が投げられるべき");
        failed++;
    }
    catch (const std::exception& e)
    {
        printSuccess("正しく例外が投げられました: " + std::string(e.what()));
        printSuccess("結果: テスト成功 - 例外処理が正常に動作");
        passed++;
    }

    // Test 3: Grade too low (151)
    printProgress(3, total);
    printTest("Invalid Grade - Too Low");
    printInfo("目的: 無効な等級が拒否されることを確認");
    printInfo("テスト内容: 等級151（最大値150を上回る）");
    printInfo("期待結果: GradeTooLowExceptionが投げられる");
    try
    {
        Bureaucrat b3("Charlie", 151);
        printError("エラー: 無効な等級でBureaucratが作成されました！");
        printError("結果: テスト失敗 - 例外が投げられるべき");
        failed++;
    }
    catch (const std::exception& e)
    {
        printSuccess("正しく例外が投げられました: " + std::string(e.what()));
        printSuccess("結果: テスト成功 - 例外処理が正常に動作");
        passed++;
    }

    // Test 4: Increment grade
    printProgress(4, total);
    printTest("Grade Increment (Promotion)");
    printInfo("目的: 昇進システムをテスト（等級番号が減少）");
    printInfo("テスト内容: 等級3から等級2への昇進");
    printInfo("期待結果: 等級が3から2に減少する");
    try
    {
        Bureaucrat b4("David", 3);
        printInfo("昇進前: " + std::string(b4.getName()) + " (等級: " + std::to_string(b4.getGrade()) + ")");
        b4.incrementGrade();
        printSuccess("昇進後: " + std::string(b4.getName()) + " (等級: " + std::to_string(b4.getGrade()) + ")");
        printSuccess("結果: テスト成功 - 昇進が正常に動作");
        passed++;
    }
    catch (const std::exception& e)
    {
        printError("昇進に失敗: " + std::string(e.what()));
        printError("結果: テスト失敗 - 昇進は成功すべき");
        failed++;
    }

    // Test 5: Decrement grade
    printProgress(5, total);
    printTest("Grade Decrement (Demotion)");
    printInfo("目的: 降格システムをテスト（等級番号が増加）");
    printInfo("テスト内容: 等級148から等級149への降格");
    printInfo("期待結果: 等級が148から149に増加する");
    try
    {
        Bureaucrat b5("Eve", 148);
        printInfo("降格前: " + std::string(b5.getName()) + " (等級: " + std::to_string(b5.getGrade()) + ")");
        b5.decrementGrade();
        printSuccess("降格後: " + std::string(b5.getName()) + " (等級: " + std::to_string(b5.getGrade()) + ")");
        printSuccess("結果: テスト成功 - 降格が正常に動作");
        passed++;
    }
    catch (const std::exception& e)
    {
        printError("降格に失敗: " + std::string(e.what()));
        printError("結果: テスト失敗 - 降格は成功すべき");
        failed++;
    }

    // Test 6: Increment grade too high (grade 1)
    printProgress(6, total);
    printTest("Boundary Value Testing - Maximum Grade");
    printInfo("目的: 等級境界でのエッジケースをテスト");
    printInfo("テスト内容: 等級1（最大値）- これ以上昇進できない");
    printInfo("期待結果: 等級1からの昇進試行時に例外が投げられる");
    printInfo("理由: 等級1は最高の等級");
    try
    {
        Bureaucrat b6("Frank", 1);
        printInfo("昇進試行前: " + std::string(b6.getName()) + " (等級: " + std::to_string(b6.getGrade()) + ")");
        b6.incrementGrade();
        printError("エラー: 昇進が成功してしまいました！");
        printError("結果: テスト失敗 - 例外が投げられるべき");
        failed++;
    }
    catch (const std::exception& e)
    {
        printSuccess("正しく例外が投げられました: " + std::string(e.what()));
        printSuccess("結果: テスト成功 - 境界保護が正常に動作");
        passed++;
    }

    // Test 7: Decrement grade too low (grade 150)
    printProgress(7, total);
    printTest("Boundary Value Testing - Minimum Grade");
    printInfo("目的: 等級境界でのエッジケースをテスト");
    printInfo("テスト内容: 等級150（最小値）- これ以上降格できない");
    printInfo("期待結果: 等級150からの降格試行時に例外が投げられる");
    printInfo("理由: 等級150は最低の等級");
    try
    {
        Bureaucrat b7("Grace", 150);
        printInfo("降格試行前: " + std::string(b7.getName()) + " (等級: " + std::to_string(b7.getGrade()) + ")");
        b7.decrementGrade();
        printError("エラー: 降格が成功してしまいました！");
        printError("結果: テスト失敗 - 例外が投げられるべき");
        failed++;
    }
    catch (const std::exception& e)
    {
        printSuccess("正しく例外が投げられました: " + std::string(e.what()));
        printSuccess("結果: テスト成功 - 境界保護が正常に動作");
        passed++;
    }

    // Test 8: Copy constructor and assignment
    printProgress(8, total);
    printTest("Orthodox Canonical Form (OCF) Test");
    printInfo("目的: コピーコンストラクタと代入演算子をテスト");
    printInfo("テスト内容: オブジェクトのコピーと代入");
    printInfo("期待結果: オブジェクトが正しくコピーされる");
    printInfo("理由: OCFは適切なオブジェクトライフサイクル管理を保証");
    try
    {
        Bureaucrat b8("Henry", 75);
        Bureaucrat b9(b8);  // Copy constructor
        Bureaucrat b10("Ivy", 100);
        b10 = b8;  // Assignment operator
        
        printSuccess("元のオブジェクト: " + std::string(b8.getName()) + " (等級: " + std::to_string(b8.getGrade()) + ")");
        printSuccess("コピー: " + std::string(b9.getName()) + " (等級: " + std::to_string(b9.getGrade()) + ")");
        printSuccess("代入後: " + std::string(b10.getName()) + " (等級: " + std::to_string(b10.getGrade()) + ")");
        printSuccess("結果: テスト成功 - OCF実装が正常に動作");
        passed++;
    }
    catch (const std::exception& e)
    {
        printError("OCFテストに失敗: " + std::string(e.what()));
        printError("結果: テスト失敗 - OCF実装に問題がある");
        failed++;
    }

    // Learning points
    printInfo("学習ポイント:");
    printInfo("   - コンストラクタ検証により無効なオブジェクトを防止");
    printInfo("   - 例外処理によりコードを堅牢にする");
    printInfo("   - 境界値テストによりエッジケースを発見");
    printInfo("   - OCFにより適切なオブジェクトライフサイクル管理を保証");

    // Test summary
    printTestSummary(passed, failed, total);
    
    printHeader("All Tests Completed! 🎉");
    return 0;
}
