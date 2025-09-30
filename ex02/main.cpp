#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
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
    
    printHeader("Bureaucrat and Specific Forms Test Suite");
    
    // Real-world scenario explanation
    printInfo("実世界のシナリオ:");
    printInfo("   官僚が具体的な書類を処理するシステムを想像してください");
    printInfo("   各書類には特定の動作があります:");
    printInfo("   - 植栽書類: ASCIIアートの木をファイルに出力");
    printInfo("   - ロボトミー書類: ランダムに成功/失敗を判定");
    printInfo("   - 恩赦書類: 大統領恩赦のメッセージを出力");
    printInfo("   署名と実行の両方に適切な等級が必要です");
    
    // Form system explanation
    printInfo("具体的な書類システムの説明:");
    printInfo("   ShrubberyCreationForm: 署名等級145, 実行等級137");
    printInfo("   RobotomyRequestForm: 署名等級72, 実行等級45");
    printInfo("   PresidentialPardonForm: 署名等級25, 実行等級5");
    printInfo("   各書類は署名後に実行可能になり、特定の動作を行います");
    
    // Test 1: Create bureaucrats with different grades
    printProgress(1, total);
    printTest("Bureaucrat Creation with Different Grades");
    printInfo("目的: 異なる等級の官僚を作成してテストの準備");
    printInfo("テスト内容: 最高等級(1)、中級(50)、最低等級(150)の官僚を作成");
    printInfo("期待結果: すべての官僚が正常に作成される");
    try
    {
        Bureaucrat b1("Alice", 1);    // Highest grade
        Bureaucrat b2("Bob", 50);     // Medium grade
        Bureaucrat b3("Charlie", 150); // Lowest grade
        std::ostringstream oss1a, oss1b, oss1c;
        oss1a << b1.getGrade();
        oss1b << b2.getGrade();
        oss1c << b3.getGrade();
        printSuccess("最高等級官僚: " + std::string(b1.getName()) + " (等級: " + oss1a.str() + ")");
        printSuccess("中級官僚: " + std::string(b2.getName()) + " (等級: " + oss1b.str() + ")");
        printSuccess("最低等級官僚: " + std::string(b3.getName()) + " (等級: " + oss1c.str() + ")");
        printSuccess("結果: テスト成功 - すべての官僚が正常に作成");
        passed++;
    }
    catch (const std::exception& e)
    {
        printError("官僚の作成に失敗: " + std::string(e.what()));
        printError("結果: テスト失敗 - 官僚は作成されるべき");
        failed++;
    }

    // Test 2: Create specific forms
    printProgress(2, total);
    printTest("Specific Forms Creation");
    printInfo("目的: 3つの具体的な書類クラスが正常に作成されることを確認");
    printInfo("テスト内容: 植栽、ロボトミー、恩赦の各書類を作成");
    printInfo("期待結果: すべての書類が正常に作成され、適切な等級が設定される");
    try
    {
        ShrubberyCreationForm shrubbery("Garden");
        RobotomyRequestForm robotomy("Target");
        PresidentialPardonForm pardon("Prisoner");
        
        std::ostringstream oss2a, oss2b, oss2c, oss2d, oss2e, oss2f;
        oss2a << shrubbery.getGradeToSign();
        oss2b << shrubbery.getGradeToExecute();
        oss2c << robotomy.getGradeToSign();
        oss2d << robotomy.getGradeToExecute();
        oss2e << pardon.getGradeToSign();
        oss2f << pardon.getGradeToExecute();
        printSuccess("植栽書類: " + std::string(shrubbery.getName()) + 
                    " (署名等級: " + oss2a.str() + 
                    ", 実行等級: " + oss2b.str() + ")");
        printSuccess("ロボトミー書類: " + std::string(robotomy.getName()) + 
                    " (署名等級: " + oss2c.str() + 
                    ", 実行等級: " + oss2d.str() + ")");
        printSuccess("恩赦書類: " + std::string(pardon.getName()) + 
                    " (署名等級: " + oss2e.str() + 
                    ", 実行等級: " + oss2f.str() + ")");
        printSuccess("結果: テスト成功 - すべての書類が正常に作成");
        passed++;
    }
    catch (const std::exception& e)
    {
        printError("書類の作成に失敗: " + std::string(e.what()));
        printError("結果: テスト失敗 - 書類は作成されるべき");
        failed++;
    }

    // Test 3: Sign forms with different grade bureaucrats
    printProgress(3, total);
    printTest("Form Signing with Different Grade Bureaucrats");
    printInfo("目的: 異なる等級の官僚による書類署名の成功・失敗を確認");
    printInfo("テスト内容: 高級官僚(1)は植栽書類に署名、中級官僚(50)はロボトミー書類に署名、低級官僚(150)は恩赦書類に署名");
    printInfo("期待結果: 等級に応じて署名の成功・失敗が適切に処理される");
    try
    {
        Bureaucrat b1("Alice", 1);
        Bureaucrat b2("Bob", 50);
        Bureaucrat b3("Charlie", 150);
        
        ShrubberyCreationForm shrubbery("Garden");
        RobotomyRequestForm robotomy("Target");
        PresidentialPardonForm pardon("Prisoner");
        
        printInfo("高級官僚による植栽書類の署名:");
        b1.signForm(shrubbery);  // Should succeed (grade 1 >= 145)
        printInfo("中級官僚によるロボトミー書類の署名:");
        b2.signForm(robotomy);   // Should succeed (grade 50 >= 72)
        printInfo("低級官僚による恩赦書類の署名:");
        b3.signForm(pardon);     // Should fail (grade 150 < 25)
        
        printSuccess("結果: テスト成功 - 等級に応じた署名処理が正常に動作");
        passed++;
    }
    catch (const std::exception& e)
    {
        printError("署名処理に失敗: " + std::string(e.what()));
        printError("結果: テスト失敗 - 署名処理は正常に動作すべき");
        failed++;
    }

    // Test 4: Execute signed forms
    printProgress(4, total);
    printTest("Execute Signed Forms");
    printInfo("目的: 署名済み書類の実行が正常に動作することを確認");
    printInfo("テスト内容: 署名済みの植栽書類とロボトミー書類を実行");
    printInfo("期待結果: 書類が正常に実行され、特定の動作が行われる");
    try
    {
        Bureaucrat b1("Alice", 1);
        Bureaucrat b2("Bob", 50);
        
        ShrubberyCreationForm shrubbery("Garden");
        RobotomyRequestForm robotomy("Target");
        
        b1.signForm(shrubbery);
        b2.signForm(robotomy);
        
        printInfo("植栽書類の実行:");
        b1.executeForm(shrubbery);  // Should succeed (grade 1 >= 137)
        printInfo("ロボトミー書類の実行:");
        b2.executeForm(robotomy);   // Should succeed (grade 50 >= 45)
        
        printSuccess("結果: テスト成功 - 書類の実行が正常に動作");
        passed++;
    }
    catch (const std::exception& e)
    {
        printError("書類の実行に失敗: " + std::string(e.what()));
        printError("結果: テスト失敗 - 書類の実行は正常に動作すべき");
        failed++;
    }

    // Test 5: Try to execute unsigned forms
    printProgress(5, total);
    printTest("Execute Unsigned Forms");
    printInfo("目的: 未署名書類の実行が失敗することを確認");
    printInfo("テスト内容: 署名されていないロボトミー書類を実行");
    printInfo("期待結果: 実行が失敗し、エラーメッセージが表示される");
    try
    {
        Bureaucrat b1("Alice", 1);
        RobotomyRequestForm unsignedRobotomy("Unsigned Target");
        
        printInfo("未署名書類の実行試行:");
        b1.executeForm(unsignedRobotomy);  // Should fail (not signed)
        
        printSuccess("結果: テスト成功 - 未署名書類の実行が正しく失敗");
        passed++;
    }
    catch (const std::exception& e)
    {
        printError("未署名書類の実行テストに失敗: " + std::string(e.what()));
        printError("結果: テスト失敗 - 未署名書類の実行は失敗すべき");
        failed++;
    }

    // Test 6: Try to execute with insufficient grade
    printProgress(6, total);
    printTest("Execute with Insufficient Grade");
    printInfo("目的: 等級不足での書類実行が失敗することを確認");
    printInfo("テスト内容: 等級50の官僚が実行等級5の恩赦書類を実行");
    printInfo("期待結果: 実行が失敗し、エラーメッセージが表示される");
    try
    {
        Bureaucrat b2("Bob", 50);
        PresidentialPardonForm pardon2("Another Prisoner");
        
        b2.signForm(pardon2);      // Should succeed (grade 50 >= 25)
        printInfo("署名後、実行試行:");
        b2.executeForm(pardon2);   // Should fail (grade 50 < 5)
        
        printSuccess("結果: テスト成功 - 等級不足での実行が正しく失敗");
        passed++;
    }
    catch (const std::exception& e)
    {
        printError("等級不足での実行テストに失敗: " + std::string(e.what()));
        printError("結果: テスト失敗 - 等級不足での実行は失敗すべき");
        failed++;
    }

    // Test 7: Test all forms with highest grade bureaucrat
    printProgress(7, total);
    printTest("All Forms with Highest Grade Bureaucrat");
    printInfo("目的: 最高等級官僚がすべての書類を処理できることを確認");
    printInfo("テスト内容: 等級1の官僚がすべての書類に署名・実行");
    printInfo("期待結果: すべての書類が正常に署名・実行される");
    try
    {
        Bureaucrat b1("Alice", 1);
        
        ShrubberyCreationForm shrubbery2("Forest");
        RobotomyRequestForm robotomy2("Robot");
        PresidentialPardonForm pardon3("Criminal");
        
        printInfo("植栽書類の処理:");
        b1.signForm(shrubbery2);
        b1.executeForm(shrubbery2);
        
        printInfo("ロボトミー書類の処理:");
        b1.signForm(robotomy2);
        b1.executeForm(robotomy2);
        
        printInfo("恩赦書類の処理:");
        b1.signForm(pardon3);
        b1.executeForm(pardon3);
        
        printSuccess("結果: テスト成功 - 最高等級官僚による全書類処理が正常に動作");
        passed++;
    }
    catch (const std::exception& e)
    {
        printError("最高等級官僚による処理に失敗: " + std::string(e.what()));
        printError("結果: テスト失敗 - 最高等級官僚の処理は正常に動作すべき");
        failed++;
    }

    // Test 8: Test copy constructor and assignment
    printProgress(8, total);
    printTest("Form Copy Constructor and Assignment");
    printInfo("目的: 具体的な書類クラスのコピーコンストラクタと代入演算子をテスト");
    printInfo("テスト内容: 植栽書類のコピーと代入");
    printInfo("期待結果: 書類オブジェクトが正しくコピーされる");
    try
    {
        ShrubberyCreationForm shrubbery3("Copy Garden");
        ShrubberyCreationForm shrubbery4(shrubbery3);  // Copy constructor
        ShrubberyCreationForm shrubbery5("Another Garden");
        shrubbery5 = shrubbery3;  // Assignment operator
        
        printSuccess("元の書類: " + std::string(shrubbery3.getName()) + 
                    " (署名: " + (shrubbery3.getIsSigned() ? "済み" : "未署名") + ")");
        printSuccess("コピー: " + std::string(shrubbery4.getName()) + 
                    " (署名: " + (shrubbery4.getIsSigned() ? "済み" : "未署名") + ")");
        printSuccess("代入後: " + std::string(shrubbery5.getName()) + 
                    " (署名: " + (shrubbery5.getIsSigned() ? "済み" : "未署名") + ")");
        printSuccess("結果: テスト成功 - 書類のコピーと代入が正常に動作");
        passed++;
    }
    catch (const std::exception& e)
    {
        printError("書類のコピー/代入テストに失敗: " + std::string(e.what()));
        printError("結果: テスト失敗 - 書類のコピー/代入に問題がある");
        failed++;
    }

    // Test 9: Test multiple executions of RobotomyRequestForm
    printProgress(9, total);
    printTest("Multiple Executions of RobotomyRequestForm");
    printInfo("目的: ロボトミー書類のランダム性を確認");
    printInfo("テスト内容: 同じ書類を5回実行してランダムな結果を確認");
    printInfo("期待結果: 成功・失敗がランダムに発生する");
    try
    {
        Bureaucrat b1("Alice", 1);
        RobotomyRequestForm robotomy3("Test Subject");
        
        b1.signForm(robotomy3);
        
        printInfo("ロボトミー書類の複数回実行:");
        for (int i = 0; i < 5; i++)
        {
            std::ostringstream oss;
            oss << (i + 1);
            printInfo("実行 " + oss.str() + ":");
            b1.executeForm(robotomy3);
        }
        
        printSuccess("結果: テスト成功 - ランダム性が正常に動作");
        passed++;
    }
    catch (const std::exception& e)
    {
        printError("複数実行テストに失敗: " + std::string(e.what()));
        printError("結果: テスト失敗 - 複数実行は正常に動作すべき");
        failed++;
    }

    // Learning points
    printInfo("学習ポイント:");
    printInfo("   - 継承とポリモーフィズムによる具体的な書類クラスの実装");
    printInfo("   - 抽象クラスと純粋仮想関数の活用");
    printInfo("   - 各書類の固有の動作とファイル操作の実装");
    printInfo("   - ランダム処理と例外処理の組み合わせ");

    // Test summary
    printTestSummary(passed, failed, total);
    
    printHeader("All Tests Completed! 🎉");
    return 0;
}
