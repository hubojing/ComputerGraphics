#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

// 屏幕宽，高
int screen_width = 800;
int screen_height = 600;

int main()
{
	// 初始化GLFW
	glfwInit();                                                     // 初始化GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);                  // OpenGL版本为3.3，主次版本号均设为3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 使用核心模式(无需向后兼容性)
	glfwWindowHint(GLFW_RESIZABLE, false);						    // 不可改变窗口大小

	//查看GLFW版本
	int Major, Minor, Rev;
	glfwGetVersion(&Major, &Minor, &Rev);
	printf("GLFW %d.%d.%d initialized\n", Major, Minor, Rev);

	// 创建窗口
	GLFWwindow* window = glfwCreateWindow(screen_width, screen_height, "HelloWorld", nullptr, nullptr);
	if (window == nullptr)
	{	// 如果窗口创建失败
		std::cout << "Failed to Create OpenGL Context" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window); // 将窗口的上下文设置为当前线程的主上下文

	// 初始化GLAD，加载OpenGL函数指针地址的函数
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// 指定当前视口尺寸
	glViewport(0, 0, screen_width, screen_height);

	// 渲染循环
	while (!glfwWindowShouldClose(window))
	{
		// 清空颜色缓冲
		glClearColor(0.0f, 0.34f, 0.57f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);// 交换缓冲
		glfwPollEvents();//是否有触发事件(比如键盘输入、鼠标移动等）
	}

	// 退出程序
	glfwTerminate();

	return 0;
}
