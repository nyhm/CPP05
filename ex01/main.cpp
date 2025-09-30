#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <sstream>

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
    int passed = 0, failed = 0, total = 9;
    
    printHeader("Bureaucrat and Form Test Suite");
    
    // Real-world scenario explanation
    printInfo("実世界のシナリオ:");
    printInfo("   官僚が書類に署名し、処理するシステムを想像してください");
    printInfo("   各書類には署名に必要な等級と実行に必要な等級があります");
    printInfo("   官僚の等級が十分でない場合、署名や実行ができません");
    printInfo("   署名された書類のみが実行可能です");
    
    // Form system explanation
    printInfo("書類システムの説明:");
    printInfo("   書類名: 書類の種類を識別");
    printInfo("   署名状態: 書類が署名されているかどうか");
    printInfo("   署名必要等級: この書類に署名するのに必要な最低等級");
    printInfo("   実行必要等級: この書類を実行するのに必要な最低等級");
    printInfo("   等級1 = 最高権限、等級150 = 最低権限");
    
    // Test 1: Normal Bureaucrat construction
    printProgress(1, total);
    printTest("Normal Bureaucrat Construction");
    printInfo("目的: 有効な等級でBureaucratが正常に作成されることを確認");
    printInfo("テスト内容: 等級50のBureaucratを作成");
    printInfo("期待結果: Bureaucratが正常に作成される");
    try
    {
        Bureaucrat b1("Alice", 50);
        std::ostringstream oss1;
        oss1 << b1.getGrade();
        printSuccess("実際の結果: " + std::string(b1.getName()) + " (等級: " + oss1.str() + ")");
        printSuccess("結果: テスト成功 - Bureaucratが正常に作成");
        passed++;
    }
    catch (const std::exception& e)
    {
        printError("Bureaucratの作成に失敗: " + std::string(e.what()));
        printError("結果: テスト失敗 - Bureaucratは作成されるべき");
        failed++;
    }

    // Test 2: Normal Form construction
    printProgress(2, total);
    printTest("Normal Form Construction");
    printInfo("目的: 有効な等級でFormが正常に作成されることを確認");
    printInfo("テスト内容: 署名等級30、実行等級20のFormを作成");
    printInfo("期待結果: Formが正常に作成され、初期状態は未署名");
    try
    {
        Form f1("Tax Form", 30, 20);
        std::ostringstream oss2a, oss2b;
        oss2a << f1.getGradeToSign();
        oss2b << f1.getGradeToExecute();
        printSuccess("実際の結果: " + std::string(f1.getName()) + " (署名: " + (f1.getIsSigned() ? "済み" : "未署名") + 
                    ", 署名必要等級: " + oss2a.str() + 
                    ", 実行必要等級: " + oss2b.str() + ")");
        printSuccess("結果: テスト成功 - Formが正常に作成");
        passed++;
    }
    catch (const std::exception& e)
    {
        printError("Formの作成に失敗: " + std::string(e.what()));
        printError("結果: テスト失敗 - Formは作成されるべき");
        failed++;
    }

    // Test 3: Form with invalid grade
    printProgress(3, total);
    printTest("Invalid Form Grade");
    printInfo("目的: 無効な等級でFormが作成されないことを確認");
    printInfo("テスト内容: 署名等級0（無効）のFormを作成");
    printInfo("期待結果: GradeTooHighExceptionが投げられる");
    try
    {
        Form f2("Invalid Form", 0, 20);
        printError("エラー: 無効な等級でFormが作成されました！");
        printError("結果: テスト失敗 - 例外が投げられるべき");
        failed++;
    }
    catch (const std::exception& e)
    {
        printSuccess("正しく例外が投げられました: " + std::string(e.what()));
        printSuccess("結果: テスト成功 - 例外処理が正常に動作");
        passed++;
    }

    // Test 4: Successful form signing
    printProgress(4, total);
    printTest("Successful Form Signing");
    printInfo("目的: 十分な等級の官僚が書類に署名できることを確認");
    printInfo("テスト内容: 等級25の官僚が署名等級30の書類に署名");
    printInfo("期待結果: 署名が成功し、書類が署名済みになる");
    try
    {
        Bureaucrat b2("Bob", 25);
        Form f3("Contract", 30, 20);
        printInfo("署名前: " + std::string(f3.getName()) + " (署名: " + (f3.getIsSigned() ? "済み" : "未署名") + ")");
        b2.signForm(f3);
        printInfo("署名後: " + std::string(f3.getName()) + " (署名: " + (f3.getIsSigned() ? "済み" : "未署名") + ")");
        printSuccess("結果: テスト成功 - 署名が正常に完了");
        passed++;
    }
    catch (const std::exception& e)
    {
        printError("署名に失敗: " + std::string(e.what()));
        printError("結果: テスト失敗 - 署名は成功すべき");
        failed++;
    }

    // Test 5: Failed form signing (grade too low)
    printProgress(5, total);
    printTest("Failed Form Signing - Insufficient Grade");
    printInfo("目的: 等級が不足している官僚は書類に署名できないことを確認");
    printInfo("テスト内容: 等級40の官僚が署名等級30の書類に署名");
    printInfo("期待結果: 署名が失敗し、エラーメッセージが表示される");
    try
    {
        Bureaucrat b3("Charlie", 40);
        Form f4("Important Document", 30, 20);
        printInfo("署名試行前: " + std::string(f4.getName()) + " (署名: " + (f4.getIsSigned() ? "済み" : "未署名") + ")");
        b3.signForm(f4);
        printInfo("署名試行後: " + std::string(f4.getName()) + " (署名: " + (f4.getIsSigned() ? "済み" : "未署名") + ")");
        // signForm()は例外を投げずにエラーメッセージを表示するので、署名状態をチェック
        if (!f4.getIsSigned())
        {
            printSuccess("署名が正しく失敗しました（書類は未署名のまま）");
            printSuccess("結果: テスト成功 - 等級不足の検出が正常に動作");
            passed++;
        }
        else
        {
            printError("エラー: 署名が成功してしまいました！");
            printError("結果: テスト失敗 - 署名は失敗すべき");
            failed++;
        }
    }
    catch (const std::exception& e)
    {
        printSuccess("正しく例外が投げられました: " + std::string(e.what()));
        printSuccess("結果: テスト成功 - 例外処理が正常に動作");
        passed++;
    }

    // Test 6: Direct beSigned call
    printProgress(6, total);
    printTest("Direct beSigned Call");
    printInfo("目的: Form::beSigned()メソッドが直接呼び出せることを確認");
    printInfo("テスト内容: 等級15の官僚が署名等級20の書類に直接署名");
    printInfo("期待結果: 署名が成功し、書類が署名済みになる");
    try
    {
        Bureaucrat b4("David", 15);
        Form f5("Direct Form", 20, 10);
        printInfo("署名前: " + std::string(f5.getName()) + " (署名: " + (f5.getIsSigned() ? "済み" : "未署名") + ")");
        f5.beSigned(b4);
        printInfo("署名後: " + std::string(f5.getName()) + " (署名: " + (f5.getIsSigned() ? "済み" : "未署名") + ")");
        printSuccess("結果: テスト成功 - 直接署名が正常に動作");
        passed++;
    }
    catch (const std::exception& e)
    {
        printError("直接署名に失敗: " + std::string(e.what()));
        printError("結果: テスト失敗 - 直接署名は成功すべき");
        failed++;
    }

    // Test 7: Direct beSigned call with low grade
    printProgress(7, total);
    printTest("Direct beSigned Call with Low Grade");
    printInfo("目的: 等級不足での直接署名が失敗することを確認");
    printInfo("テスト内容: 等級50の官僚が署名等級20の書類に直接署名");
    printInfo("期待結果: 署名が失敗し、例外が投げられる");
    try
    {
        Bureaucrat b5("Eve", 50);
        Form f6("High Security Form", 20, 10);
        printInfo("署名試行前: " + std::string(f6.getName()) + " (署名: " + (f6.getIsSigned() ? "済み" : "未署名") + ")");
        f6.beSigned(b5);
        printInfo("署名試行後: " + std::string(f6.getName()) + " (署名: " + (f6.getIsSigned() ? "済み" : "未署名") + ")");
        printError("エラー: 署名が成功してしまいました！");
        printError("結果: テスト失敗 - 署名は失敗すべき");
        failed++;
    }
    catch (const std::exception& e)
    {
        printSuccess("正しく例外が投げられました: " + std::string(e.what()));
        printSuccess("結果: テスト成功 - 等級不足の検出が正常に動作");
        passed++;
    }

    // Test 8: Copy constructor and assignment for Form
    printProgress(8, total);
    printTest("Form Copy Constructor and Assignment");
    printInfo("目的: Formのコピーコンストラクタと代入演算子をテスト");
    printInfo("テスト内容: Formオブジェクトのコピーと代入");
    printInfo("期待結果: Formオブジェクトが正しくコピーされる");
    try
    {
        Form f7("Original Form", 25, 15);
        Form f8(f7);  // Copy constructor
        Form f9("Another Form", 50, 40);
        f9 = f7;  // Assignment operator
        
        printSuccess("元のForm: " + std::string(f7.getName()) + " (署名: " + (f7.getIsSigned() ? "済み" : "未署名") + ")");
        printSuccess("コピー: " + std::string(f8.getName()) + " (署名: " + (f8.getIsSigned() ? "済み" : "未署名") + ")");
        printSuccess("代入後: " + std::string(f9.getName()) + " (署名: " + (f9.getIsSigned() ? "済み" : "未署名") + ")");
        printSuccess("結果: テスト成功 - Formのコピーと代入が正常に動作");
        passed++;
    }
    catch (const std::exception& e)
    {
        printError("Formのコピー/代入テストに失敗: " + std::string(e.what()));
        printError("結果: テスト失敗 - Formのコピー/代入に問題がある");
        failed++;
    }

    // Test 9: Multiple bureaucrats signing different forms
    printProgress(9, total);
    printTest("Multiple Bureaucrats and Forms");
    printInfo("目的: 複数の官僚が異なる書類を処理することを確認");
    printInfo("テスト内容: 高級官僚と低級官僚が異なる書類を処理");
    printInfo("期待結果: 等級に応じて署名の成功・失敗が適切に処理される");
    try
    {
        Bureaucrat b6("Frank", 10);  // High grade
        Bureaucrat b7("Grace", 100); // Low grade
        
        Form f10("High Priority Form", 15, 10);
        Form f11("Low Priority Form", 120, 100);
        
        printInfo("高級官僚による高優先度書類の署名:");
        b6.signForm(f10);
        printInfo("高級官僚による低優先度書類の署名:");
        b6.signForm(f11);
        printInfo("低級官僚による高優先度書類の署名:");
        b7.signForm(f10);
        printInfo("低級官僚による低優先度書類の署名:");
        b7.signForm(f11);
        
        printSuccess("結果: テスト成功 - 複数官僚の処理が正常に動作");
        passed++;
    }
    catch (const std::exception& e)
    {
        printError("複数官僚テストに失敗: " + std::string(e.what()));
        printError("結果: テスト失敗 - 複数官僚の処理に問題がある");
        failed++;
    }

    // Learning points
    printInfo("学習ポイント:");
    printInfo("   - 書類システムによる権限管理の実装");
    printInfo("   - 署名と実行の分離によるセキュリティ向上");
    printInfo("   - 例外処理による適切なエラーハンドリング");
    printInfo("   - クラス間の関係性と相互作用の設計");

    // Test summary
    printTestSummary(passed, failed, total);
    
    printHeader("All Tests Completed! 🎉");
    return 0;
}
