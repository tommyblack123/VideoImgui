// VideoImgui.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "StringUtil.h"


GLFWwindow* gMainWindow = nullptr;


int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    gMainWindow = glfwCreateWindow(800, 600, "fuck", nullptr, nullptr);

    glfwMakeContextCurrent(gMainWindow);
    glfwSwapInterval(0);


    //初始化imgui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext(nullptr);
    auto& io = ImGui::GetIO();
    io.Fonts->AddFontFromFileTTF("c:/windows/fonts/msyh.ttc", 18.0f, nullptr, io.Fonts->GetGlyphRangesChineseFull());


    ImGui::StyleColorsClassic();

    ImGui_ImplGlfw_InitForOpenGL(gMainWindow, true);
    ImGui_ImplOpenGL3_Init("#version 330");


    char Textbuf[255] = { "fuck Textbuf" };

    std::string TextString = "";

    ImVec4 color;

    while (glfwWindowShouldClose(gMainWindow) == false)
    {

        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();

        ImGui::NewFrame();

        ImGui::Begin("fuckyou");

        
        ImGui::Text(StringUtil::GBKtoUTF8(TextString).data());

        if (ImGui::Button("my button"))
        {
            TextString = "我点了你";
            printf("clicked my button\r\n");
        }

        ImGui::InputText("Test Txt Box", Textbuf, IM_ARRAYSIZE(Textbuf));

		if (ImGui::BeginListBox("test List Box"))
		{
			for (size_t i = 0; i < 100; i++)
			{
				if (ImGui::Selectable(std::to_string(i).c_str()))
				{
                    TextString = std::to_string(i);
				}
			}
			ImGui::EndListBox();
		}



		{
			// Using the _simplified_ one-liner Combo() api here
			// See "Combo" section for examples of how to use the more flexible BeginCombo()/EndCombo() api.
			const char* items[] = { "AAAA", "BBBB", "CCCC", "DDDD", "EEEE", "FFFF", "GGGG", "HHHH", "IIIIIII", "JJJJ", "KKKKKKK" };
			static int item_current = 0;
            if (ImGui::Combo("combo", &item_current, items, IM_ARRAYSIZE(items)))
            {

                printf("combox index :%d\r\n", item_current);
            }

		}


        ImGui::ColorEdit4("Test Color", (float*)&color);

        ImGui::End();



        ImGui::ShowDemoWindow();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(gMainWindow);
        glfwPollEvents();
    }





    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
