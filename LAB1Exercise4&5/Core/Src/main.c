/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "softwaretimer.h"
#include "7segments.h"
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
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim2);
  struct Sevenled ledA;
  struct Sevenled ledB;

  Initialize7Segments(&ledA, GPIOA, GPIO_PIN_8, GPIO_PIN_9, GPIO_PIN_10, GPIO_PIN_11, GPIO_PIN_12, GPIO_PIN_13, GPIO_PIN_14);
  Initialize7Segments(&ledB, GPIOB, GPIO_PIN_3, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6, GPIO_PIN_7, GPIO_PIN_8, GPIO_PIN_9);
  unsigned short lednumA = 5;
  unsigned short lednumB = 3;
  int trigger2A = 0;
  int trigger3A = 1;
  int trigger5A = 0;
  int trigger2B = 1;
  int trigger3B = 0;
  int trigger5B = 0;
  int status = 0;

  setTimer(300);
  setTimer0(100);
  setTimer1(100);
  setTimer2(100);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
      {
        /* USER CODE END WHILE */
    	  if (timerflag0 == 1) {
    		  			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_1);
    		  			setTimer0(100);
    		  		}
    	switch(status)
    		{
    		case 1:
    			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);
    			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);
    			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
    			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0);
    			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
    			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 1);
    			if (timerflag == 1) {
    				status = 2;
    				setTimer(200);
    			}
    			break;
    		case 2:
    			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);
    			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);
    			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
    			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0);
    			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 1);
    			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 0);
    			if (timerflag == 1) {
    				status = 3;
    				setTimer(300);
    			}
    			break;
    		case 3:
    			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
    			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);
    			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 1);
    			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 1);
    			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
    			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 0);
    			if (timerflag == 1) {
    				status = 4;
    				setTimer(200);
    			}
    			break;
    		case 4:
    			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
    			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 1);
    			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
    			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 1);
    			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
    			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 0);
    			if (timerflag == 1) {
    				status = 1;
    				setTimer(300);
    			}
    			break;
    		default:
    			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);
    			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);
    			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
    			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0);
    			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
    			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 1);
    			if (timerflag == 1) {
    				status = 2;
    				setTimer(200);
    			}
    			break;
    		}
		switch(lednumA)
			{
    	case 0:
    		SetAndDisplay7Segments(&ledA, 0);
    		if (timerflag1 == 1)
    		{
    			if (trigger5A) {lednumA = 5; trigger5A = 0; trigger3A = 1; setTimer1(80); break;}
    			if (trigger3A) {lednumA = 3; trigger3A = 0; trigger2A = 1; setTimer1(80); break;}
    			if (trigger2A) {lednumA = 2; trigger2A = 0; trigger5A = 1; setTimer1(80); break;}
    		}
    		break;
    	case 1:
    		SetAndDisplay7Segments(&ledA, 1);
    		if (timerflag1 == 1)
    		{
    			lednumA = 0;
				setTimer1(20);
    		}
    		break;
    	case 2:
    		SetAndDisplay7Segments(&ledA, 2);
    		if (timerflag1 == 1)
    		{
    			lednumA = 1;
				setTimer1(100);
    		}
    		break;
    	case 3:
    		SetAndDisplay7Segments(&ledA, 3);
    		if (timerflag1 == 1)
    		{
    			lednumA = 2;
				setTimer1(100);
    		}
    		break;
    	case 4:
    		SetAndDisplay7Segments(&ledA, 4);
    		if (timerflag1 == 1)
    		{
    			lednumA = 3;
				setTimer1(100);
    		}
    		break;
    	case 5:
    		SetAndDisplay7Segments(&ledA, 5);
    		if (timerflag1 == 1)
    		{
    			lednumA = 4;
				setTimer1(100);
    		}
    		break;
    	case 6:
    		SetAndDisplay7Segments(&ledA, 6);
    		if (timerflag1 == 1)
    		{
    			lednumA = 5;
				setTimer1(100);
    		}
    		break;
    	case 7:
    		SetAndDisplay7Segments(&ledA, 7);
    		if (timerflag1 == 1)
    		{
    			lednumA = 6;
				setTimer1(100);
    		}
    		break;
    	case 8:
    		SetAndDisplay7Segments(&ledA, 8);
    		if (timerflag1 == 1)
    		{
    			lednumA = 7;
				setTimer1(100);
    		}
    		break;
    	case 9:
    		SetAndDisplay7Segments(&ledA, 9);
    		if (timerflag1 == 1)
    		{
    			lednumA = 8;
				setTimer1(100);
    		}
    		break;
    	default:
    		SetAndDisplay7Segments(&ledA, 0);
			setTimer1(50);
			break;
    	}
				
    	switch(lednumB)
    	{
    	case 0:
    		SetAndDisplay7Segments(&ledB, 0);
    		if (timerflag2 == 1)
    		{
    			if (trigger5B) {lednumB = 5; trigger5B = 0; trigger3B = 1; setTimer2(80); break;}
    			if (trigger3B) {lednumB = 3; trigger3B = 0; trigger2B = 1; setTimer2(80); break;}
    			if (trigger2B) {lednumB = 2; trigger2B = 0; trigger5B = 1; setTimer2(80); break;}
    			setTimer2(80);
    		}
    		break;
    	case 1:
    		SetAndDisplay7Segments(&ledB, 1);
    		if (timerflag2 == 1)
    		{
    			lednumB = 0;
    			setTimer2(20);
    		}
    		break;
    	case 2:
    		SetAndDisplay7Segments(&ledB, 2);
    		if (timerflag2 == 1)
    		{
    			lednumB = 1;
    			setTimer2(100);
    		}
    		break;
    	case 3:
    		SetAndDisplay7Segments(&ledB, 3);
    		if (timerflag2 == 1)
    		{
    			lednumB = 2;
    			setTimer2(100);
    		}
    		break;
    	case 4:
    		SetAndDisplay7Segments(&ledB, 4);
    		if (timerflag2 == 1)
    		{
    			lednumB = 3;
    			setTimer2(100);
    		}
    		break;
    	case 5:
    		SetAndDisplay7Segments(&ledB, 5);
    		if (timerflag2 == 1)
    		{
    			lednumB = 4;
    			setTimer2(100);
    		}
    		break;
    	case 6:
    		SetAndDisplay7Segments(&ledB, 6);
    		if (timerflag2 == 1)
    		{
    			lednumB = 5;
    			setTimer2(100);
    		}
    		break;
    	case 7:
    		SetAndDisplay7Segments(&ledB, 7);
    		if (timerflag2 == 1)
    		{
    			lednumB = 6;
    			setTimer2(100);
    		}
    		break;
    	case 8:
    		SetAndDisplay7Segments(&ledB, 8);
    		if (timerflag2 == 1)
    		{
    			lednumB = 7;
    			setTimer2(100);
    		}
    		break;
    	case 9:
    		SetAndDisplay7Segments(&ledB, 9);
    		if (timerflag2 == 1)
    		{
    			lednumB = 8;
    			setTimer2(100);
    		}
    		break;
    	default:
    		SetAndDisplay7Segments(&ledB, 0);
    		setTimer2(50);
    		break;
    	}
        /* USER CODE BEGIN 3 */
      }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
                          |GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11
                          |GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
                          |GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA1 PA5 PA6 PA7
                           PA8 PA9 PA10 PA11
                           PA12 PA13 PA14 */
  GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
                          |GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11
                          |GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB2 PB3
                           PB4 PB5 PB6 PB7
                           PB8 PB9 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
                          |GPIO_PIN_8|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	runTimer();
	runTimer0();
	runTimer1();
	runTimer2();
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
