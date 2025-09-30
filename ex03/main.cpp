#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
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
    
    printHeader("Intern Class Test Suite");
    
    // Real-world scenario explanation
    printInfo("実世界のシナリオ:");
    printInfo("   インターンが書類の作成を担当するシステムを想像してください");
    printInfo("   インターンは書類名を聞いて、対応する書類を作成します");
    printInfo("   インターンには名前や等級はなく、書類作成が唯一の仕事です");
    printInfo("   ファクトリメソッドパターンで動的に書類を生成します");
    
    // Intern system explanation
    printInfo("インターンシステムの説明:");
    printInfo("   makeForm(書類名, ターゲット) で書類を作成");
    printInfo("   対応する書類: shrubbery creation, robotomy request, presidential pardon");
    printInfo("   無効な書類名の場合はエラーメッセージを表示");
    printInfo("   メンバ関数ポインタの配列を使用したクリーンな実装");
    
    // Test 1: Create Intern
    printProgress(1, total);
    printTest("Intern Creation");
    printInfo("目的: Internクラスが正常に作成されることを確認");
    printInfo("テスト内容: デフォルトコンストラクタでInternを作成");
    printInfo("期待結果: Internが正常に作成される");
    try
    {
        Intern intern;
        printSuccess("実際の結果: Internが正常に作成されました");
        printSuccess("結果: テスト成功 - Internの作成が正常に動作");
        passed++;
    }
    catch (const std::exception& e)
    {
        printError("Internの作成に失敗: " + std::string(e.what()));
        printError("結果: テスト失敗 - Internは作成されるべき");
        failed++;
    }

    // Test 2: Create ShrubberyCreationForm
    printProgress(2, total);
    printTest("Create ShrubberyCreationForm");
    printInfo("目的: インターンが植栽書類を作成できることを確認");
    printInfo("テスト内容: 'shrubbery creation'で植栽書類を作成");
    printInfo("期待結果: ShrubberyCreationFormが正常に作成される");
    try
    {
        Intern intern;
        AForm* form = intern.makeForm("shrubbery creation", "Garden");
        if (form != NULL)
        {
            printSuccess("実際の結果: " + std::string(form->getName()) + " が作成されました");
            printSuccess("結果: テスト成功 - 植栽書類の作成が正常に動作");
            delete form;
            passed++;
        }
        else
        {
            printError("エラー: 書類の作成に失敗しました");
            printError("結果: テスト失敗 - 書類は作成されるべき");
            failed++;
        }
    }
    catch (const std::exception& e)
    {
        printError("植栽書類の作成に失敗: " + std::string(e.what()));
        printError("結果: テスト失敗 - 植栽書類は作成されるべき");
        failed++;
    }

    // Test 3: Create RobotomyRequestForm
    printProgress(3, total);
    printTest("Create RobotomyRequestForm");
    printInfo("目的: インターンがロボトミー書類を作成できることを確認");
    printInfo("テスト内容: 'robotomy request'でロボトミー書類を作成");
    printInfo("期待結果: RobotomyRequestFormが正常に作成される");
    try
    {
        Intern intern;
        AForm* form = intern.makeForm("robotomy request", "Bender");
        if (form != NULL)
        {
            printSuccess("実際の結果: " + std::string(form->getName()) + " が作成されました");
            printSuccess("結果: テスト成功 - ロボトミー書類の作成が正常に動作");
            delete form;
            passed++;
        }
        else
        {
            printError("エラー: 書類の作成に失敗しました");
            printError("結果: テスト失敗 - 書類は作成されるべき");
            failed++;
        }
    }
    catch (const std::exception& e)
    {
        printError("ロボトミー書類の作成に失敗: " + std::string(e.what()));
        printError("結果: テスト失敗 - ロボトミー書類は作成されるべき");
        failed++;
    }

    // Test 4: Create PresidentialPardonForm
    printProgress(4, total);
    printTest("Create PresidentialPardonForm");
    printInfo("目的: インターンが恩赦書類を作成できることを確認");
    printInfo("テスト内容: 'presidential pardon'で恩赦書類を作成");
    printInfo("期待結果: PresidentialPardonFormが正常に作成される");
    try
    {
        Intern intern;
        AForm* form = intern.makeForm("presidential pardon", "Prisoner");
        if (form != NULL)
        {
            printSuccess("実際の結果: " + std::string(form->getName()) + " が作成されました");
            printSuccess("結果: テスト成功 - 恩赦書類の作成が正常に動作");
            delete form;
            passed++;
        }
        else
        {
            printError("エラー: 書類の作成に失敗しました");
            printError("結果: テスト失敗 - 書類は作成されるべき");
            failed++;
        }
    }
    catch (const std::exception& e)
    {
        printError("恩赦書類の作成に失敗: " + std::string(e.what()));
        printError("結果: テスト失敗 - 恩赦書類は作成されるべき");
        failed++;
    }

    // Test 5: Case insensitive form names
    printProgress(5, total);
    printTest("Case Insensitive Form Names");
    printInfo("目的: 大文字小文字を区別しない書類名の処理を確認");
    printInfo("テスト内容: 'SHRUBBERY CREATION'で植栽書類を作成");
    printInfo("期待結果: 大文字でも正常に書類が作成される");
    try
    {
        Intern intern;
        AForm* form = intern.makeForm("SHRUBBERY CREATION", "Forest");
        if (form != NULL)
        {
            printSuccess("実際の結果: " + std::string(form->getName()) + " が作成されました");
            printSuccess("結果: テスト成功 - 大文字小文字の処理が正常に動作");
            delete form;
            passed++;
        }
        else
        {
            printError("エラー: 書類の作成に失敗しました");
            printError("結果: テスト失敗 - 書類は作成されるべき");
            failed++;
        }
    }
    catch (const std::exception& e)
    {
        printError("大文字小文字の処理に失敗: " + std::string(e.what()));
        printError("結果: テスト失敗 - 大文字小文字の処理は正常に動作すべき");
        failed++;
    }

    // Test 6: Invalid form name
    printProgress(6, total);
    printTest("Invalid Form Name");
    printInfo("目的: 無効な書類名でエラーメッセージが表示されることを確認");
    printInfo("テスト内容: 'invalid form'で書類を作成");
    printInfo("期待結果: NULLが返され、エラーメッセージが表示される");
    try
    {
        Intern intern;
        AForm* form = intern.makeForm("invalid form", "Target");
        if (form == NULL)
        {
            printSuccess("実際の結果: NULLが返され、エラーメッセージが表示されました");
            printSuccess("結果: テスト成功 - 無効な書類名の処理が正常に動作");
            passed++;
        }
        else
        {
            printError("エラー: 無効な書類名なのに書類が作成されました");
            printError("結果: テスト失敗 - 無効な書類名はNULLを返すべき");
            delete form;
            failed++;
        }
    }
    catch (const std::exception& e)
    {
        printError("無効な書類名の処理に失敗: " + std::string(e.what()));
        printError("結果: テスト失敗 - 無効な書類名の処理は正常に動作すべき");
        failed++;
    }

    // Test 7: Complete workflow with Bureaucrat
    printProgress(7, total);
    printTest("Complete Workflow with Bureaucrat");
    printInfo("目的: インターンが作成した書類を官僚が処理する完全なワークフローを確認");
    printInfo("テスト内容: インターンが書類を作成→官僚が署名・実行");
    printInfo("期待結果: 完全なワークフローが正常に動作する");
    try
    {
        Intern intern;
        Bureaucrat bureaucrat("Alice", 1);
        
        AForm* form = intern.makeForm("robotomy request", "Test Subject");
        if (form != NULL)
        {
            printInfo("書類作成後、官僚による処理:");
            bureaucrat.signForm(*form);
            bureaucrat.executeForm(*form);
            
            printSuccess("実際の結果: 完全なワークフローが正常に動作しました");
            printSuccess("結果: テスト成功 - インターン→官僚の連携が正常に動作");
            delete form;
            passed++;
        }
        else
        {
            printError("エラー: 書類の作成に失敗しました");
            printError("結果: テスト失敗 - 書類は作成されるべき");
            failed++;
        }
    }
    catch (const std::exception& e)
    {
        printError("完全なワークフローに失敗: " + std::string(e.what()));
        printError("結果: テスト失敗 - 完全なワークフローは正常に動作すべき");
        failed++;
    }

    // Test 8: Copy constructor and assignment
    printProgress(8, total);
    printTest("Intern Copy Constructor and Assignment");
    printInfo("目的: Internのコピーコンストラクタと代入演算子をテスト");
    printInfo("テスト内容: Internオブジェクトのコピーと代入");
    printInfo("期待結果: Internオブジェクトが正しくコピーされる");
    try
    {
        Intern intern1;
        Intern intern2(intern1);  // Copy constructor
        Intern intern3;
        intern3 = intern1;  // Assignment operator
        
        // Test that both interns can create forms
        AForm* form1 = intern1.makeForm("shrubbery creation", "Garden1");
        AForm* form2 = intern2.makeForm("shrubbery creation", "Garden2");
        AForm* form3 = intern3.makeForm("shrubbery creation", "Garden3");
        
        if (form1 != NULL && form2 != NULL && form3 != NULL)
        {
            printSuccess("実際の結果: すべてのInternが正常に書類を作成しました");
            printSuccess("結果: テスト成功 - Internのコピーと代入が正常に動作");
            delete form1;
            delete form2;
            delete form3;
            passed++;
        }
        else
        {
            printError("エラー: コピー/代入後のInternが正常に動作しません");
            printError("結果: テスト失敗 - Internのコピー/代入に問題がある");
            if (form1) delete form1;
            if (form2) delete form2;
            if (form3) delete form3;
            failed++;
        }
    }
    catch (const std::exception& e)
    {
        printError("Internのコピー/代入テストに失敗: " + std::string(e.what()));
        printError("結果: テスト失敗 - Internのコピー/代入に問題がある");
        failed++;
    }

    // Learning points
    printInfo("学習ポイント:");
    printInfo("   - ファクトリメソッドパターンによる動的オブジェクト生成");
    printInfo("   - メンバ関数ポインタとマップを使用したクリーンな実装");
    printInfo("   - 文字列とクラスの関連付けによる柔軟な設計");
    printInfo("   - エラーハンドリングとメモリ管理の重要性");

    // Test summary
    printTestSummary(passed, failed, total);
    
    printHeader("All Tests Completed! 🎉");
    return 0;
}
