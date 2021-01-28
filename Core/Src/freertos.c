/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId LED1TaskHandle;
osThreadId LED2TaskHandle;
osThreadId LED3TaskHandle;
osThreadId LED4TaskHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void LED1_Task(void const * argument);
void LED2_Tak(void const * argument);
void LED3_Task(void const * argument);
void LED4_Task(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of LED1Task */
  osThreadDef(LED1Task, LED1_Task, osPriorityNormal, 0, 128);
  LED1TaskHandle = osThreadCreate(osThread(LED1Task), NULL);

  /* definition and creation of LED2Task */
  osThreadDef(LED2Task, LED2_Tak, osPriorityNormal, 0, 128);
  LED2TaskHandle = osThreadCreate(osThread(LED2Task), NULL);

  /* definition and creation of LED3Task */
  osThreadDef(LED3Task, LED3_Task, osPriorityNormal, 0, 128);
  LED3TaskHandle = osThreadCreate(osThread(LED3Task), NULL);

  /* definition and creation of LED4Task */
  osThreadDef(LED4Task, LED4_Task, osPriorityNormal, 0, 128);
  LED4TaskHandle = osThreadCreate(osThread(LED4Task), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */

  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_LED1_Task */
/**
  * @brief  Function implementing the LED1Task thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_LED1_Task */
void LED1_Task(void const * argument)
{
  /* USER CODE BEGIN LED1_Task */
  /* Infinite loop */

  for(;;)
  {
      HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
	  osDelay(100);
  }
  /* USER CODE END LED1_Task */
}

/* USER CODE BEGIN Header_LED2_Tak */
/**
* @brief Function implementing the LED2Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_LED2_Tak */
void LED2_Tak(void const * argument)
{
  /* USER CODE BEGIN LED2_Tak */
  /* Infinite loop */
  for(;;)
  {
      HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
	  osDelay(500);
  }
  /* USER CODE END LED2_Tak */
}

/* USER CODE BEGIN Header_LED3_Task */
/**
* @brief Function implementing the LED3Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_LED3_Task */
void LED3_Task(void const * argument)
{
  /* USER CODE BEGIN LED3_Task */
  /* Infinite loop */
  for(;;)
  {
      HAL_GPIO_TogglePin(LED3_GPIO_Port, LED3_Pin);
    osDelay(1000);
  }
  /* USER CODE END LED3_Task */
}

/* USER CODE BEGIN Header_LED4_Task */
/**
* @brief Function implementing the LED4Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_LED4_Task */
void LED4_Task(void const * argument)
{
  /* USER CODE BEGIN LED4_Task */
  /* Infinite loop */
  for(;;)
  {
      HAL_GPIO_TogglePin(LED4_GPIO_Port, LED4_Pin);
	  osDelay(50);
  }
  /* USER CODE END LED4_Task */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
